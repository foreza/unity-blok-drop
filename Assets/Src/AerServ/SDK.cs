namespace AerServ {

	using System;
	using UnityEngine;
	using System.Collections;
	using System.Collections.Generic;

	public class SDK {

		/** Banner alignment constants.  These are used to align the banner **/
		public const int BANNER_TOP = 0;
		public const int BANNER_BOTTOM = 1;

		/** SDK Events for publishers.  These are used to communicate information from the SDK code to the application code **/
		public const int AD_FAILED = 0;
		public const int AD_LOADED = 1;
		public const int AD_COMPLETED = 2;
		public const int AD_CLICKED = 3;
		public const int AD_DISMISSED = 4;
		public const int PRELOAD_READY = 5;
		public const int VC_READY = 7;
		public const int VC_REWARDED = 8;

		public const String PARAM_USER_ID = "userId";
		public const String PARAM_DEBUG = "debug";
		public const String PARAM_VERBOSE = "verbose";
		public const String PARAM_PRECACHE = "precache";
		public const String PARAM_ENV = "env";
		public const String PARAM_TIMEOUT_MILLIS = "timeoutMillis";
		public const String PARAM_PUB_KEYS = "pubKeys";
		public const String PARAM_KEYWORDS = "keywords";

		public SDK() {
		}

		public static void InitSdk(String siteId) {
			if (Application.platform == RuntimePlatform.Android) {
				AerServNativeAdapter.AERSERVSDK_ANDROID_init(siteId);
			} else if(Application.platform == RuntimePlatform.IPhonePlayer) {
				AerServNativeAdapter.AERSERVSDK_IOS_init(siteId);
			} else {
				Debug.Log("no platform found to init on");
			}
		}

		public static void LoadInterstitial(String plc, OnAerServEvent onAerServEvent,
				Dictionary<string, object> config = null) {
			String configJson = convertDictionaryToJsonString(config);
			if (Application.platform == RuntimePlatform.Android) {
				AerServNativeAdapter.AERSERVSDK_ANDROID_load_interstitial(plc, onAerServEvent, configJson);
			} else if(Application.platform == RuntimePlatform.IPhonePlayer) {
				AerServNativeAdapter.AERSERVSDK_IOS_load_interstitial(plc, onAerServEvent, configJson);
			} else {
				Debug.Log("no platform found to show interstitial on");
			}
		}

		public static void PreloadInterstitial(String plc, OnAerServEvent onAerServEvent,
				Dictionary<string, object> config = null) {
			String configJson = convertDictionaryToJsonString(config);
			if (Application.platform == RuntimePlatform.Android) {
				AerServNativeAdapter.AERSERVSDK_ANDROID_preload_interstitial(plc, onAerServEvent, configJson);
			} else if(Application.platform == RuntimePlatform.IPhonePlayer) {
				AerServNativeAdapter.AERSERVSDK_IOS_preload_interstitial(plc, onAerServEvent, configJson);
			} else {
				Debug.Log("no platform found to show interstitial on");
			}
		}

		private static String convertDictionaryToJsonString(Dictionary<string, object> dictionary) {
			String jsonStr = "{";
			if (dictionary != null) {
				foreach (KeyValuePair<string, object> entry in dictionary) {
					if (entry.Value is IDictionary) {
						jsonStr += "\"" + entry.Key + "\":" + convertDictionaryToJsonString(entry.Value as Dictionary<string, object>);
					} else if (entry.Value is List<string>) {
						jsonStr += "\"" + entry.Key + "\":[";
						List<string> list = entry.Value as List<string>;
						foreach (string item in list) {
							jsonStr += "\"" + item + "\",";
						}
						if (jsonStr.EndsWith(",")) {
							jsonStr = jsonStr.TrimEnd(',');
						}
						jsonStr += "]";
					} else {
						jsonStr += "\"" + entry.Key + "\":\"" + entry.Value + "\"";
					}
					jsonStr += ",";
				}
			}
			if (jsonStr.EndsWith(",")) {
				jsonStr = jsonStr.TrimEnd(',');
			}
			jsonStr += "}";
			return jsonStr;
		}

		public static void ShowInterstitial() {

			if (Application.platform == RuntimePlatform.Android) {

				AerServNativeAdapter.AERSERVSDK_ANDROID_show_interstitial();

			} else if(Application.platform == RuntimePlatform.IPhonePlayer) {

				AerServNativeAdapter.AERSERVSDK_IOS_show_interstitial();
			
			} else {

				Debug.Log("no platform found to show interstitial on");

			}

		}

		[System.Obsolete("Use ShowInterstitial instead.")]
		public static void ShowInterstitialForPlc(String plc) {
			if (Application.platform == RuntimePlatform.Android) {
				AerServNativeAdapter.AERSERVSDK_ANDROID_show_interstitial_for_plc(plc);
			} else if(Application.platform == RuntimePlatform.IPhonePlayer) {
				AerServNativeAdapter.AERSERVSDK_IOS_show_interstitial_for_plc(plc);
			} else {
				Debug.Log("no platform found to show interstitial on");
			}
		}

		public static void ShowBanner(String plc, int width, int height, int position,
				OnAerServEvent onAerServEvent, Dictionary<string, object> config = null) {
			String configJson = convertDictionaryToJsonString(config);

			if (Application.platform == RuntimePlatform.Android) {

				AerServNativeAdapter.AERSERVSDK_ANDROID_show_banner(plc, width, height, position,
						onAerServEvent, configJson);

			} else if(Application.platform == RuntimePlatform.IPhonePlayer) {

				AerServNativeAdapter.AERSERVSDK_IOS_show_banner(plc, width, height, position,
						onAerServEvent, configJson);

			} else {

				Debug.Log("no platform found to show banner on");

			}

		}

		public static void KillBanner() {

			if (Application.platform == RuntimePlatform.Android) {

				AerServNativeAdapter.AERSERVSDK_ANDROID_kill_banner();

			} else if(Application.platform == RuntimePlatform.IPhonePlayer) {

				AerServNativeAdapter.AERSERVSDK_IOS_kill_banner();
			} else {

				Debug.Log("no platform found to kill banner on");

			}

		}

	}

}
