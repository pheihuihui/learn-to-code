//var http = require('https');
//
//var page = "https://www.bilibili.com/"
//
//var html = '';
//
//http.get(page, function(res) {
//    res.on('data', function(data) {
//        html += data;
//    });
//    res.on('end', function() {
//        console.log(html);
//    });
//});
//
//document.html = html
//document.getElementsByClassName('mask')

const puppeteer = require('puppeteer');

(async () => {
    const browser = await puppeteer.launch();
    page = await browser.newPage();
    await page.goto('https://www.bilibili.com/', {waitUntil: 'load'});
    const newPage = await page.evaluate(() => {
        return document.getElementById('chief_recommend')
    });
    console.log(newPage)
})();