$("#refreshbutton").click(function () {
    $.get("http://localhost:12650/Home/CellsData", function (res) {
        if (res) {
            $("div#id00").style = "greencell";
            //$("div#id00").hide();
        } else {
            $("div#id00").style = "graycell";
            //$("div#id00").show();
        }
        console.log(res);
    });
});