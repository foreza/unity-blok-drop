using System;
using System.Runtime.InteropServices;
using UnityEngine;

[AttributeUsage (AttributeTargets.Method)]
public sealed class MonoPInvokeCallbackAttribute : Attribute
{
		public MonoPInvokeCallbackAttribute (Type t) {}
}

namespace AerServ {

	public delegate void OnAerServEvent(int eventType, String args);

	public class AerServNativeAdapter {

		[DllImport ("aerserv-sdk-unity")]
		public static extern void AERSERVSDK_ANDROID_init(String siteId);

		[DllImport ("aerserv-sdk-unity")]
		public static extern void AERSERVSDK_ANDROID_load_interstitial(String plc, OnAerServEvent onAerServEvent, String configJson);

		[DllImport ("aerserv-sdk-unity")]
		public static extern void AERSERVSDK_ANDROID_preload_interstitial(String plc, OnAerServEvent onAerServEvent, String configJson);

		[DllImport ("aerserv-sdk-unity")]
		public static extern void AERSERVSDK_ANDROID_show_interstitial();

		[DllImport ("aerserv-sdk-unity")]
		public static extern void AERSERVSDK_ANDROID_show_interstitial_for_plc(String plc);

		[DllImport ("aerserv-sdk-unity")]
		public static extern void AERSERVSDK_ANDROID_show_banner(String plc, int width, int height, int position, OnAerServEvent onAerServEvent, String configJson);

		[DllImport ("aerserv-sdk-unity")]
		public static extern void AERSERVSDK_ANDROID_kill_banner();

		[DllImport ("__Internal")]
		public static extern void AERSERVSDK_IOS_init(String siteId);

		[DllImport ("__Internal")]
		public static extern void AERSERVSDK_IOS_load_interstitial(String plc, OnAerServEvent onAerServEvent, String configJson);

		[DllImport ("__Internal")]
		public static extern void AERSERVSDK_IOS_preload_interstitial(String plc, OnAerServEvent onAerServEvent, String configJson);

		[DllImport ("__Internal")]
		public static extern void AERSERVSDK_IOS_show_interstitial();

		[DllImport ("__Internal")]
		public static extern void AERSERVSDK_IOS_show_interstitial_for_plc(String plc);

		[DllImport ("__Internal")]
		public static extern void AERSERVSDK_IOS_show_banner(String plc, int width, int height, int position, OnAerServEvent onAerServEvent, String configJson);

		[DllImport ("__Internal")]
		public static extern void AERSERVSDK_IOS_kill_banner();

	}

}
