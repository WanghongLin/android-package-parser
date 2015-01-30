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
package com.mutter.packageparser;

/**
 * @author mutter
 *
 */
public class PackageParser {

	static {
		System.loadLibrary("PackageParser");
		nativeInit();
	}
	
	public static void main(String[] args) {
		
		PackageParser parser = new PackageParser();
		PackageInfo info = parser.dumpPackageInfo("/home/mutter/ntfs/data/pkg/apkfusion/com.tencent.mm_501_v6.0.0.57_r870003.apk");
		
		System.out.println("packageName\t:\t" + info.getPackageName());
		System.out.println("versionCode\t:\t" + info.getVersionCode());
		System.out.println("versionName\t:\t" + info.getVersionName());
		System.out.println("sdkVersion\t:\t" + info.getSdkVersion());
		System.out.println("targetSdkVersion\t:\t" + info.getTargetSdkVersion());
		System.out.println("maxSdkVersion\t:\t" + info.getMaxSdkVersion());
		System.out.println("applicationLabels\t:");
		for (String l : info.getApplicationLabel()) {
			System.out.println(l);
		}
		System.out.println("applicationIcons\t:");
		for (String i : info.getApplicationIcons()) {
			System.out.println(i);
		}
		System.out.print("densities\t:");
		for (int i : info.getDensities()) {
			System.out.print(i + " ");
		}
		System.out.println();

		System.out.print("nativeCodes\t:");
		for (String n : info.getNativeCodes()) {
			System.out.print(n + " ");
		}
		System.out.println();
		
		System.out.print("locales\t:");
		for (String l : info.getLocales()) {
			System.out.print(l + " ");
		}
		System.out.println();
		
		System.out.print("supportScreens\t:");
		for (String s : info.getSupportScreens()) {
			System.out.print(s + " ");
		}
		System.out.println();
		System.out.println("supportAnyDensity\t:\t" + info.isSupportAnyDensity());
		
		System.out.println("uses-permissions\t:");
		for (String p : info.getUsesPermissions()) {
			System.out.println(p);
		}
		
		System.out.println("uses-features\t:");
		for (String f : info.getUsesFeatures()) {
			System.out.println(f);
		}
	}
	
	private native PackageInfo dumpPackageInfo(String packagePath);
	private static native void nativeInit();
	private static native void nativeDestroy();
}
