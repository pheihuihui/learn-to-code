using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FloorController : MonoBehaviour
{
    public GameObject floorPrefab;
    public static Vector3 floorMoveSpeed;
    public float gap;
    public Vector3 floorStartSpeed;

    private void Awake()
    {
        floorMoveSpeed = floorStartSpeed;
    }

    // Use this for initialization
    void Start()
    {
        StartCoroutine(GenerateFloors());
        StartCoroutine(SpeedUp());
    }

    // Update is called once per frame
    void Update()
    {

    }

    IEnumerator GenerateFloors()
    {
        while (true)
        {
            GameObject gm = Instantiate(floorPrefab);
            yield return new WaitForSeconds(gap / (-floorMoveSpeed.x));
        }
    }

    IEnumerator SpeedUp()
    {
        while (true)
        {
            floorMoveSpeed += new Vector3(-0.1f, 0, 0);
            yield return new WaitForSeconds(1);
        }
    }
}