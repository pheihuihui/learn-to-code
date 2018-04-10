using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FloorController : MonoBehaviour
{
    public GameObject floorPrefab;
    public Vector3 floorMoveSpeed;

    private void Awake()
    {
        //Instantiate(floorPrefab);
    }

    // Use this for initialization
    void Start()
    {
        StartCoroutine(GenerateFloors());
    }

    // Update is called once per frame
    void Update()
    {
        floorMoveSpeed += new Vector3(-0.01f, 0, 0);
    }

    IEnumerator GenerateFloors()
    {
        while (true)
        {
            GameObject gm = Instantiate(floorPrefab);
            Rigidbody rd = gm.GetComponent<Rigidbody>();
            rd.velocity = floorMoveSpeed;
            yield return new WaitForSeconds(1);
        }
    }
}