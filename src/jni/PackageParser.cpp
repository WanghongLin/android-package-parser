/*
 * Copyright (C) 2015 mutter
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <jni.h>
#include "com_mutter_packageparser_PackageParser.h"
#include <iostream>
#include "Bundle.h"
#include "Main.h"

using namespace std;

#define NUMOFM(t) sizeof(t)/sizeof(JNINativeMethod)

typedef struct _package_info {

	jmethodID setPackageName;
	jmethodID setVersionCode;
	jmethodID setVersionName;
	jmethodID setSdkVersion;
	jmethodID setTargetSdkVersion;
	jmethodID setMaxSdkVersion;
	jmethodID setUsesPermissions;
	jmethodID setUsesImpliedPermissions;
	jmethodID setApplicationLabels;
	jmethodID setApplicationIcons;
	jmethodID setUsesFeatures;
	jmethodID setUsesImpliedFeatures;
	jmethodID setSupportScreens;
	jmethodID setLocales;
	jmethodID setDensities;
	jmethodID setNativeCodes;

	// field ID
	jfieldID packageName;
	jfieldID versionCode;
	jfieldID versionName;
	jfieldID sdkVersion;
	jfieldID targetSdkVersion;
	jfieldID maxSdkVersion;
	jfieldID usesPermissions;
	jfieldID usesImpliedPermissions;
	jfieldID applicationLabels;
	jfieldID applicationIcons;
	jfieldID usesFeatures;
	jfieldID usesImpliedFeatures;
	jfieldID supportScreens;
	jfieldID locales;
	jfieldID densities;
	jfieldID nativeCodes;
	jfieldID supportAnyDensity;
} PackageInfo;

// cache purpose
static PackageInfo packageInfo;
static jclass packageInfoClazz;
static jclass jStringClazz;

static jint initPackageInfo(JNIEnv* env)
{
	if (env == NULL || packageInfoClazz == NULL) {
		return JNI_ERR;
	}

	packageInfo.applicationLabels = env->GetFieldID(packageInfoClazz, "applicationLabels", "[Ljava/lang/String;");
	packageInfo.applicationIcons = env->GetFieldID(packageInfoClazz, "applicationIcons", "[Ljava/lang/String;");
	packageInfo.densities = env->GetFieldID(packageInfoClazz, "densities", "[I");
	packageInfo.locales = env->GetFieldID(packageInfoClazz, "locales", "[Ljava/lang/String;");
	packageInfo.nativeCodes = env->GetFieldID(packageInfoClazz, "nativeCodes", "[Ljava/lang/String;");
	packageInfo.packageName = env->GetFieldID(packageInfoClazz, "packageName", "Ljava/lang/String;");
	packageInfo.sdkVersion = env->GetFieldID(packageInfoClazz, "sdkVersion", "I");
	packageInfo.supportScreens = env->GetFieldID(packageInfoClazz, "supportScreens", "[Ljava/lang/String;");
	packageInfo.targetSdkVersion = env->GetFieldID(packageInfoClazz, "targetSdkVersion", "I");
	packageInfo.maxSdkVersion = env->GetFieldID(packageInfoClazz, "maxSdkVersion", "I");
	packageInfo.usesFeatures = env->GetFieldID(packageInfoClazz, "usesFeatures", "[Ljava/lang/String;");
	packageInfo.usesImpliedFeatures = env->GetFieldID(packageInfoClazz, "usesImpliedFeatures", "[Ljava/lang/String;");
	packageInfo.usesImpliedPermissions = env->GetFieldID(packageInfoClazz, "usesImpliedPermissions", "[Ljava/lang/String;");
	packageInfo.usesPermissions = env->GetFieldID(packageInfoClazz, "usesPermissions", "[Ljava/lang/String;");
	packageInfo.versionCode = env->GetFieldID(packageInfoClazz, "versionCode", "J");
	packageInfo.versionName = env->GetFieldID(packageInfoClazz, "versionName", "Ljava/lang/String;");
	packageInfo.supportAnyDensity = env->GetFieldID(packageInfoClazz, "supportAnyDensity", "Z");
	return JNI_OK;
}

JNIEXPORT jobject JNICALL dumpPackageInfo
  (JNIEnv* env, jobject object, jstring package) {
	Bundle* bundle = new Bundle();
	bundle->setCommand(kCommandDump);
	char* * argv = new char*[2];
	argv[0] = const_cast<char*>("badging");
	argv[1] = const_cast<char*>(env->GetStringUTFChars(package, 0));
	int argc = 2;

	bundle->setFileSpec(argv, argc);
	int result = doDump(bundle);
	if (result != NO_ERROR) {
		cerr << "doDump error" << endl;
		return NULL;
	}

	jobject packageInfoObj = env->AllocObject(packageInfoClazz);
	env->SetObjectField(packageInfoObj, packageInfo.versionName,
			env->NewStringUTF(bundle->getVersionName()));

	env->SetLongField(packageInfoObj, packageInfo.versionCode,
			atol(bundle->getVersionCode()));

	env->SetObjectField(packageInfoObj, packageInfo.packageName,
			env->NewStringUTF(bundle->getPackageName()));

	const size_t NL = bundle->getApplicationLabels().size();
	jobjectArray labelArrays = env->NewObjectArray(NL, jStringClazz, NULL);
	for (size_t i = 0; i < NL; i++) {
		jstring str = env->NewStringUTF(bundle->getApplicationLabels().itemAt(i).string());

		env->SetObjectArrayElement(labelArrays, i, str);
	}
	env->SetObjectField(packageInfoObj, packageInfo.applicationLabels,
			labelArrays);

	const size_t N = bundle->getApplicationIcons().size();
	jobjectArray iconArrays = env->NewObjectArray(N, jStringClazz, NULL);
	for (size_t i = 0; i < N; i++) {
		jstring str = env->NewStringUTF(bundle->getApplicationIcons().itemAt(i));
		env->SetObjectArrayElement(iconArrays, i, str);
	}
	env->SetObjectField(packageInfoObj, packageInfo.applicationIcons,
			iconArrays);

	env->SetIntField(packageInfoObj, packageInfo.targetSdkVersion,
			atoi(bundle->getTargetSdkVersion()));
	env->SetIntField(packageInfoObj, packageInfo.sdkVersion,
			atoi(bundle->getMinSdkVersion()));
	if (bundle->getMaxSdkVersion() != NULL) {
		env->SetIntField(packageInfoObj, packageInfo.maxSdkVersion,
				atoi(bundle->getMaxSdkVersion()));
	}

	const size_t D = bundle->getDensities().size();
	jintArray densityArray = env->NewIntArray(D);
	env->SetIntArrayRegion(densityArray, 0, D, bundle->getDensities().array());
	env->SetObjectField(packageInfoObj, packageInfo.densities, densityArray);

	const size_t V = bundle->getNativeCodes().size();
	jobjectArray nativeArray = env->NewObjectArray(V, jStringClazz, NULL);
	for (size_t i = 0; i < V; i++) {
		env->SetObjectArrayElement(nativeArray, i,
				env->NewStringUTF(bundle->getNativeCodes()[i]));
	}
	env->SetObjectField(packageInfoObj, packageInfo.nativeCodes, nativeArray);

	const size_t W = bundle->getLocales().size();
	jobjectArray localeArray = env->NewObjectArray(W, jStringClazz, NULL);
	for (size_t i = 0; i < W; i++) {
		env->SetObjectArrayElement(localeArray, i,
				env->NewStringUTF(bundle->getLocales()[i]));
	}
	env->SetObjectField(packageInfoObj, packageInfo.locales, localeArray);

	const size_t Z = bundle->getSupportScreens().size();
	jobjectArray supportScreenArray = env->NewObjectArray(Z, jStringClazz, NULL);
	for (size_t i = 0; i < Z; i++) {
		env->SetObjectArrayElement(supportScreenArray, i,
				env->NewStringUTF(bundle->getSupportScreens()[i]));
	}
	env->SetObjectField(packageInfoObj, packageInfo.supportScreens, supportScreenArray);

	env->SetBooleanField(packageInfoObj, packageInfo.supportAnyDensity, bundle->isSupportAnyDensity());

	const size_t NF = bundle->getUsesFeatures().size();
	jobjectArray usesFeatureArray = env->NewObjectArray(NF, jStringClazz, NULL);
	for (size_t i = 0; i < NF; i++) {
		env->SetObjectArrayElement(usesFeatureArray, i,
				env->NewStringUTF(bundle->getUsesFeatures()[i]));
	}
	env->SetObjectField(packageInfoObj, packageInfo.usesFeatures, usesFeatureArray);

	const size_t NP = bundle->getUsesPermissions().size();
	jobjectArray usesPermissionArray = env->NewObjectArray(NP, jStringClazz, NULL);
	for (size_t i = 0; i < NP; i++) {
		env->SetObjectArrayElement(usesPermissionArray, i,
				env->NewStringUTF(bundle->getUsesPermissions()[i]));
	}
	env->SetObjectField(packageInfoObj, packageInfo.usesPermissions, usesPermissionArray);

	env->ReleaseStringUTFChars(package, argv[1]);
	cout << "dumpPackageInfo" << endl;
	return packageInfoObj;
}

JNIEXPORT void JNICALL nativeInit(JNIEnv* env, jobject object)
{
	jStringClazz = reinterpret_cast<jclass>(env->NewGlobalRef(
			env->FindClass("java/lang/String")));
	if (env->ExceptionCheck()) {
		cerr << "Unable to find class java/lang/String" << endl;
	}

	packageInfoClazz = reinterpret_cast<jclass>(env->NewGlobalRef(
			env->FindClass("com/mutter/packageparser/PackageInfo")));
	if (env->ExceptionCheck()) {
		cerr << "Unable to find class com/mutter/packageparser/PackageInfo" << endl;
	}

	if (initPackageInfo(env) != JNI_OK) {
		cerr << "Unable to initial packageInfo" << endl;
	}
}

JNIEXPORT void JNICALL nativeDestroy(JNIEnv* env, jobject object)
{
	if (jStringClazz != NULL) {
		env->DeleteGlobalRef(jStringClazz);
	}
	if (packageInfoClazz != NULL) {
		env->DeleteGlobalRef(packageInfoClazz);
	}
}

static JNINativeMethod nativeMethods[] = {
		{ (char*)"dumpPackageInfo", (char*)"(Ljava/lang/String;)Lcom/mutter/packageparser/PackageInfo;", (void*)&dumpPackageInfo },
		{ (char*)"nativeInit", (char*)"()V", (void*)&nativeInit },
		{ (char*)"nativeDestroy", (char*)"()V", (void*)&nativeDestroy }
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* jvm, void* reserved)
{
	JNIEnv* env;
	jint version = 0;
	if (jvm->GetEnv((void**)&env, JNI_VERSION_1_6) == JNI_OK) {
		version = JNI_VERSION_1_6;
	} else if (jvm->GetEnv((void**)&env, JNI_VERSION_1_4) == JNI_OK) {
		version = JNI_VERSION_1_4;
	} else {
		cerr << "Get JNIEnv error" << endl;
	}

	jclass clazz = env->FindClass("com/mutter/packageparser/PackageParser");
	if (env->ExceptionCheck()) {
		cerr << "Can't not find class com/mutter/packageparser/PackageParser" << endl;
		return version;
	}

	env->RegisterNatives(clazz, nativeMethods, NUMOFM(nativeMethods));
	if (env->ExceptionCheck()) {
		cerr << "Unable to register native methods" << endl;
		return version;
	}

	cout << ">>>>>>>>>>>>>>>>>>>>JNI_OnLoad<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	return version;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* jvm, void* reserved)
{
	JNIEnv* env;
	if (jvm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
		cerr << "Unable to get JNIEnv" << endl;
		return;
	}
	if (jStringClazz != NULL && env != NULL) {
		env->DeleteGlobalRef(jStringClazz);
	}
	if (jvm->DestroyJavaVM() != JNI_OK) {
		cerr << "Unable to destroy JavaVM" << endl;
	}
}
