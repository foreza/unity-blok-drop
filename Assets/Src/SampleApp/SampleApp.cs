using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System;

namespace AerServ {

	public class SampleApp : MonoBehaviour {
		
		private String plc = "1000834";
		private static String message = "";
		private static String del = "";

		void OnGUI() {

			GUIStyle style = new GUIStyle(GUI.skin.button);
			style.fontSize = 35;

		  plc	= GUI.TextField(new Rect(Screen.width/2-150, Screen.height/2-500, 300, 100), plc, style);

			if(GUI.Button(new Rect(Screen.width/2-150, Screen.height/2-350, 300, 100), "Load Interstitial", style))
			{

				if( plc == null || plc.Equals(""))
					plc = "1000834";	
				
				message = "";
				del = "";

				Dictionary<string, object> config = generateTestConfig();
				SDK.LoadInterstitial(plc, aerServEventCallBack, config);
			}

			if(GUI.Button(new Rect(Screen.width/2-150, Screen.height/2-240, 300, 100), "Preload Interstitial", style))
			{
				if( plc == null || plc.Equals(""))
					plc = "1000834";	

				message = "";
				del = "";

				Dictionary<string, object> config = generateTestConfig();
				SDK.PreloadInterstitial(plc, aerServEventCallBack, config);
			}

			if(GUI.Button(new Rect(Screen.width/2-150, Screen.height/2-130, 300, 100), "Show Interstitial", style))
			{
				if( plc == null || plc.Equals(""))
					plc = "1000834";	

				message = "";
				del = "";
				SDK.ShowInterstitial();
			}
				
			if(GUI.Button(new Rect(Screen.width/2-150, Screen.height/2-20, 300, 100), "Load Banner", style))
			{

				if( plc == null || plc.Equals(""))
					plc = "1000834";	

				message = "";
				del = "";

				Dictionary<string, object> config = generateTestConfig();
				SDK.ShowBanner(plc, (int) 320, (int) 50, SDK.BANNER_BOTTOM, aerServEventCallBack, config);
			}

			if(GUI.Button(new Rect(Screen.width/2-150, Screen.height/2+90, 300, 100), "Kill Banner", style))
			{
				
				message = "";
				del = "";
				SDK.KillBanner();
			}

			if(GUI.Button(new Rect(Screen.width/2-150, Screen.height/2+200, 300, 100), "Init", style))
			{
				message = "";
				del = "";
				SDK.InitSdk("101190");
			}

			GUIStyle style2 = new GUIStyle(GUI.skin.textArea);
			style2.fontSize = 20;
			message = GUI.TextArea(new Rect(Screen.width/2-350, Screen.height/2+310, 700, 300), message, style2);
		}

		/** This method acts as a bridge between native code and client code **/
		[MonoPInvokeCallback (typeof (OnAerServEvent))]
		static void aerServEventCallBack(int eventType, String args) {

			String[] argsArr = (args != null) ? args.Split('|') : null;

			switch(eventType) {

				case SDK.AD_FAILED:
					message += del + "AD_FAILED invoked! message: " + argsArr[0];
					if (argsArr.Length > 1) {
						message += del + ", code: " + argsArr[1];
					}
					break;
				case SDK.AD_LOADED:
					message += del + "AD_LOADED invoked!";
					break;
				case SDK.AD_COMPLETED:
					message += del + "AD_COMPLETED invoked!";
					break;
				case SDK.AD_CLICKED:
					message += del + "AD_CLICKED invoked!";
					break;
				case SDK.AD_DISMISSED:
					message += del + "AD_DISMISSED invoked!";
					break;
				case SDK.PRELOAD_READY:
					message += del + "PRELOAD_READY invoked!";
					break;
				case SDK.VC_READY:
					message += del + "VC_READY invoked! Name: " + argsArr[0] + ", Amount: " + argsArr[1]
							+ ", Buyer name: " + argsArr[2] + ", Buyer price: " + argsArr[3];
					break;
				case SDK.VC_REWARDED:
					message += del + "VC_REWARDED invoked! Name: " + argsArr[0] + ", Amount: " + argsArr[1]
							+ ", Buyer name: " + argsArr[2] + ", Buyer price: " + argsArr[3];
					break;
				default:
					break;

			}

			del = "\n";

		}

		// Returns a dictionary that can be passed into ad requests to configure ad requests.
		// This is optional and is only included here as a sample to illustrate how it is done.
		static Dictionary<string, object> generateTestConfig() {
			Dictionary<string, object> config = new Dictionary<string, object>();
			config.Add(SDK.PARAM_USER_ID, "AerServTestUser");
			config.Add(SDK.PARAM_TIMEOUT_MILLIS, 10000);

			// Setting publisher keys
			Dictionary<string, object> pubKeys = new Dictionary<string, object>();
			pubKeys.Add("testPubKey1", "testPubKeyValue1");
			pubKeys.Add("testPubKey2", "testPubKeyValue2");
			config.Add(SDK.PARAM_PUB_KEYS, pubKeys);

			// Setting keywords
			List<string> keywords = new List<string>();
			keywords.Add("testKeyword1");
			keywords.Add("testKeyword2");
			config.Add(SDK.PARAM_KEYWORDS, keywords);

			return config;
		}
	}

}
