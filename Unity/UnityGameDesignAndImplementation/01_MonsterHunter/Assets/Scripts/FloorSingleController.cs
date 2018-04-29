using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FloorSingleController : MonoBehaviour
{
    private Vector3 speed;
    // Use this for initialization
    void Start()
    {
        Destroy(this.gameObject, 5f);
    }

    // Update is called once per frame
    void Update()
    {
        speed = FloorController.floorMoveSpeed;
        gameObject.transform.position += speed * Time.deltaTime;
    }

}
