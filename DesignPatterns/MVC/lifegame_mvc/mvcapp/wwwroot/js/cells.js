import { setInterval } from "timers";

homeurl = "http://localhost:12650"

$("#refreshbutton").click(function () {
    $.get( homeurl + "/Home/CellsData", function (res) {
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

})

function asyncCells() {
    $.get(homeurl + "/Home/CellsData", function (res) {
        
    })
}