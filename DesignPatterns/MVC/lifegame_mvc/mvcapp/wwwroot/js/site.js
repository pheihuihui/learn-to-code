// Write your JavaScript code.

//import { setInterval } from "timers";
//TODO_201805292221: Find out why import module does't work.



homeurl = "http://localhost:12650"

$("#refreshbutton").click(function () {
    $.get(homeurl + "/Home/CellsData", function (res) {
        if (res) {
            var div00 = document.getElementById("id00")
            div00.className = "greencell";
        } else {
            var div00 = document.getElementById("id00")
            div00.className = "graycell";
        }
        console.log(res);
    });
});

$(document).ready(function () {
    setInterval(asyncCells, 100)
})

function asyncCells() {
    $.get(homeurl + "/Home/CellsData", function (res) {
        $.get(homeurl + "/Home/CellsNumber", function (cells) {
            for (var i = 0; i < cells[0]; i++) {
                for (var j = 0; j < cells[1]; j++) {
                    $("input#vertical_num").value = (i * j).toString()
                    var divid = "id" + i.toString() + j.toString()
                    if (res[i][j] == true) {
                        var ddiv = document.getElementById(divid);
                        if (ddiv != null) {
                            ddiv.className = "greencell"
                        }
                        
                    } else {
                        var ddiv = document.getElementById(divid);
                        if (ddiv != null) {
                            ddiv.className = "graycell"
                        }
                    }
                }
            }
        })
    })
}