using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gravity : MonoBehaviour {

    public float gravity = -10.0F;

	// Use this for initialization
	void Start () {
		
        Physics.gravity = new Vector3(0, gravity, 0);

	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
