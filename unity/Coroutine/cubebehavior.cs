using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cubebehavior : MonoBehaviour
{

	// Use this for initialization
	void Start ()
    {
        StartCoroutine(CoroutineOne());
	}
	
	// Update is called once per frame
	void Update ()
    {
		
	}

    IEnumerator CoroutineOne()
    {
        while (true)
        {
            Debug.Log(Time.realtimeSinceStartup);
            yield return new WaitForSeconds(2);
        }
    }
}
