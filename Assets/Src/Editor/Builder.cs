using UnityEngine;
using UnityEditor;
 
public class Builder
{
    public static void BuildAndroidSampleApp()
    {
        string[] assets = {"Assets/Scene0.unity"};
        BuildPipeline.BuildPlayer(assets, "Sample.apk", BuildTarget.Android, BuildOptions.None);
    }
}
