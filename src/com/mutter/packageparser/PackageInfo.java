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
public class PackageInfo {
	
	private String packageName;
	private long versionCode;
	private String versionName;
	private int sdkVersion;
	private int targetSdkVersion;
	private int maxSdkVersion;
	private String[] usesPermissions;
	private String[] usesImpliedPermissions;
	private String[] applicationLabels;
	private String[] applicationIcons;
	private String[] usesFeatures;
	private String[] usesImpliedFeatures;
	private String[] supportScreens;
	private String[] locales;
	private int[] densities;
	private String[] nativeCodes;
	
	private boolean supportAnyDensity;
	private boolean hasMainActivity;
	private boolean hasWidgetReceivers;
	private boolean hasImeService;
	private boolean hasWallpaperService;
	private boolean hasOtherActivities;
	private boolean isSearchable;
	private boolean hasOtherReceivers;
	private boolean hasOtherServices;

	/**
	 * @return the applicationLabels
	 */
	public String[] getApplicationLabels() {
		return applicationLabels;
	}
	/**
	 * @param applicationLabels the applicationLabels to set
	 */
	public void setApplicationLabels(String[] applicationLabels) {
		this.applicationLabels = applicationLabels;
	}
	/**
	 * @return the hasWallpaperService
	 */
	public boolean isHasWallpaperService() {
		return hasWallpaperService;
	}
	/**
	 * @param hasWallpaperService the hasWallpaperService to set
	 */
	public void setHasWallpaperService(boolean hasWallpaperService) {
		this.hasWallpaperService = hasWallpaperService;
	}
	/**
	 * @return the hasOtherActivities
	 */
	public boolean isHasOtherActivities() {
		return hasOtherActivities;
	}
	/**
	 * @param hasOtherActivities the hasOtherActivities to set
	 */
	public void setHasOtherActivities(boolean hasOtherActivities) {
		this.hasOtherActivities = hasOtherActivities;
	}
	/**
	 * @return the isSearchable
	 */
	public boolean isSearchable() {
		return isSearchable;
	}
	/**
	 * @param isSearchable the isSearchable to set
	 */
	public void setSearchable(boolean isSearchable) {
		this.isSearchable = isSearchable;
	}
	/**
	 * @return the hasOtherReceivers
	 */
	public boolean isHasOtherReceivers() {
		return hasOtherReceivers;
	}
	/**
	 * @param hasOtherReceivers the hasOtherReceivers to set
	 */
	public void setHasOtherReceivers(boolean hasOtherReceivers) {
		this.hasOtherReceivers = hasOtherReceivers;
	}
	/**
	 * @return the hasOtherServices
	 */
	public boolean isHasOtherServices() {
		return hasOtherServices;
	}
	/**
	 * @param hasOtherServices the hasOtherServices to set
	 */
	public void setHasOtherServices(boolean hasOtherServices) {
		this.hasOtherServices = hasOtherServices;
	}
	
	/**
	 * @return the packageName
	 */
	public String getPackageName() {
		return packageName;
	}
	/**
	 * @param packageName the packageName to set
	 */
	public void setPackageName(String packageName) {
		this.packageName = packageName;
	}
	/**
	 * @return the versionCode
	 */
	public long getVersionCode() {
		return versionCode;
	}
	/**
	 * @param versionCode the versionCode to set
	 */
	public void setVersionCode(long versionCode) {
		this.versionCode = versionCode;
	}
	/**
	 * @return the versionName
	 */
	public String getVersionName() {
		return versionName;
	}
	/**
	 * @param versionName the versionName to set
	 */
	public void setVersionName(String versionName) {
		this.versionName = versionName;
	}
	/**
	 * @return the sdkVersion
	 */
	public int getSdkVersion() {
		return sdkVersion;
	}
	/**
	 * @param sdkVersion the sdkVersion to set
	 */
	public void setSdkVersion(int sdkVersion) {
		this.sdkVersion = sdkVersion;
	}
	/**
	 * @return the targetSdkVersion
	 */
	public int getTargetSdkVersion() {
		return targetSdkVersion;
	}
	/**
	 * @param targetSdkVersion the targetSdkVersion to set
	 */
	public void setTargetSdkVersion(int targetSdkVersion) {
		this.targetSdkVersion = targetSdkVersion;
	}
	/**
	 * @return the usesPermissions
	 */
	public String[] getUsesPermissions() {
		return usesPermissions;
	}
	/**
	 * @param usesPermissions the usesPermissions to set
	 */
	public void setUsesPermissions(String[] usesPermissions) {
		this.usesPermissions = usesPermissions;
	}
	/**
	 * @return the usesImpliedPermissions
	 */
	public String[] getUsesImpliedPermissions() {
		return usesImpliedPermissions;
	}
	/**
	 * @param usesImpliedPermissions the usesImpliedPermissions to set
	 */
	public void setUsesImpliedPermissions(String[] usesImpliedPermissions) {
		this.usesImpliedPermissions = usesImpliedPermissions;
	}
	/**
	 * @return the applicationLabel
	 */
	public String[] getApplicationLabel() {
		return applicationLabels;
	}
	/**
	 * @param applicationLabel the applicationLabel to set
	 */
	public void setApplicationLabel(String[] applicationLabels) {
		this.applicationLabels = applicationLabels;
	}
	/**
	 * @return the usesFeatures
	 */
	public String[] getUsesFeatures() {
		return usesFeatures;
	}
	/**
	 * @param usesFeatures the usesFeatures to set
	 */
	public void setUsesFeatures(String[] usesFeatures) {
		this.usesFeatures = usesFeatures;
	}
	/**
	 * @return the usesImpliedFeatures
	 */
	public String[] getUsesImpliedFeatures() {
		return usesImpliedFeatures;
	}
	/**
	 * @param usesImpliedFeatures the usesImpliedFeatures to set
	 */
	public void setUsesImpliedFeatures(String[] usesImpliedFeatures) {
		this.usesImpliedFeatures = usesImpliedFeatures;
	}
	/**
	 * @return the supportScreens
	 */
	public String[] getSupportScreens() {
		return supportScreens;
	}
	/**
	 * @param supportScreens the supportScreens to set
	 */
	public void setSupportScreens(String[] supportScreens) {
		this.supportScreens = supportScreens;
	}
	/**
	 * @return the locales
	 */
	public String[] getLocales() {
		return locales;
	}
	/**
	 * @param locales the locales to set
	 */
	public void setLocales(String[] locales) {
		this.locales = locales;
	}
	/**
	 * @return the densities
	 */
	public int[] getDensities() {
		return densities;
	}
	/**
	 * @param densities the densities to set
	 */
	public void setDensities(int[] densities) {
		this.densities = densities;
	}
	/**
	 * @return the nativeCodes
	 */
	public String[] getNativeCodes() {
		return nativeCodes;
	}
	/**
	 * @param nativeCodes the nativeCodes to set
	 */
	public void setNativeCodes(String[] nativeCodes) {
		this.nativeCodes = nativeCodes;
	}
	/**
	 * @return the applicationIcons
	 */
	public String[] getApplicationIcons() {
		return applicationIcons;
	}
	/**
	 * @param applicationIcons the applicationIcons to set
	 */
	public void setApplicationIcons(String[] applicationIcons) {
		this.applicationIcons = applicationIcons;
	}
	/**
	 * @return the maxSdkVersion
	 */
	public int getMaxSdkVersion() {
		return maxSdkVersion;
	}
	/**
	 * @param maxSdkVersion the maxSdkVersion to set
	 */
	public void setMaxSdkVersion(int maxSdkVersion) {
		this.maxSdkVersion = maxSdkVersion;
	}
	/**
	 * @return the hasMainActivity
	 */
	public boolean isHasMainActivity() {
		return hasMainActivity;
	}
	/**
	 * @param hasMainActivity the hasMainActivity to set
	 */
	public void setHasMainActivity(boolean hasMainActivity) {
		this.hasMainActivity = hasMainActivity;
	}
	/**
	 * @return the hasWidgetReceivers
	 */
	public boolean isHasWidgetReceivers() {
		return hasWidgetReceivers;
	}
	/**
	 * @param hasWidgetReceivers the hasWidgetReceivers to set
	 */
	public void setHasWidgetReceivers(boolean hasWidgetReceivers) {
		this.hasWidgetReceivers = hasWidgetReceivers;
	}
	/**
	 * @return the hasImeService
	 */
	public boolean isHasImeService() {
		return hasImeService;
	}
	/**
	 * @param hasImeService the hasImeService to set
	 */
	public void setHasImeService(boolean hasImeService) {
		this.hasImeService = hasImeService;
	}
	/**
	 * @return the supportAnyDensity
	 */
	public boolean isSupportAnyDensity() {
		return supportAnyDensity;
	}
	/**
	 * @param supportAnyDensity the supportAnyDensity to set
	 */
	public void setSupportAnyDensity(boolean supportAnyDensity) {
		this.supportAnyDensity = supportAnyDensity;
	}
}
