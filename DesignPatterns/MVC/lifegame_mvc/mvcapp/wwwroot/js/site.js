// Write your JavaScript code.

//import { setInterval } from "timers";
//TODO_201805292221: Find out why import module does't work.



homeurl = "http://localhost:12650"
var grayCellInnerHtml = "<div class=\"cell\" style=\"background-color: darkgray \" />"
var greenCellInnerHtml = "<div class=\"cell\" style=\"background-color: darkgreen \" />"


$(document).ready(function () {
    setInterval(asyncCells, 1000)
})

function asyncCells() {
    $.get(homeurl + "/Home/CellsData", function (res) {
        $.get(homeurl + "/Home/CellsNumber", function (cells) {
            for (var i = 0; i < cells[0]; i++) {
                for (var j = 0; j < cells[1]; j++) {
                    $("input#vertical_num").value = (i * j).toString()
                    var divid = "id_" + j.toString() + "_" + i.toString()
                    if (res[i][j] == true) {
                        var ddiv = document.getElementById(divid);
                        if (ddiv != null) {
                            ddiv.innerHTML = greenCellInnerHtml
                        }
                    } else {
                        var ddiv = document.getElementById(divid);
                        if (ddiv != null) {
                            ddiv.innerHTML = grayCellInnerHtml
                        }
                    }
                }
            }
        })
    })
}

function resetGame() {

}


$(".cont").click(function () {
    var ele = this.getElementsByClassName("incont")[0]
    if (ele.innerHTML.indexOf("gray") >= 0 && ele.innerHTML.indexOf("green") == -1) {
        ele.innerHTML = greenCellInnerHtml
    }
    else if (ele.innerHTML.indexOf("green") >= 0 && ele.innerHTML.indexOf("gray") == -1) {
        ele.innerHTML = grayCellInnerHtml
    }
})