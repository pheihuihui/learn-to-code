// Write your JavaScript code.
function changeCell() {
    var dd = document.getElementById(id).style;
    if (dd == greencell) {
        document.getElementById(id).style = graycell;
    } else if (dd == graycell) {
        document.getElementById(id).style = greencell;
    }
}

$('div').click(function () {
    var ss = this.style;
    if (ss == greencell) {
        this.style = graycell;
    } else if (ss == graycell) {
        this.style = greencell;
    }
})