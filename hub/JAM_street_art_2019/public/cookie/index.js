$(document).ready(function() {
    setTimeout(function(){
      $('#loading').fadeOut('slow');
    }, 7000);

    setTimeout(function(){
        $('#cookie').fadeIn('slow');
      }, 8000);
});

var mySize = 52;
function zoomin() {
    if (mySize === 0) return;
    let myImg = document.getElementById("cky");
    mySize += 10;
    if(mySize >= 200 && mySize !== 0) {
        mySize = 0;
        setInterval(() => {
            document.location.href = 'http://' + window.location.hostname + (window.location.port !== '80' && window.location.port !== '443' ? ':' + window.location.port : '') + '/paint';
        }, 3000);
        myImg.parentElement.removeChild(myImg);
    } else {
        myImg.style.width = mySize.toString() + "px";
        myImg.style.height = mySize.toString() + "px";
    }
}

function zoomout() {
    if (mySize === 0) return;
    let myImg = document.getElementById("cky");
    if (mySize === 0)
        return;
    mySize -= 3;
    if (mySize < 52)
        mySize = 52;
    myImg.style.width = mySize.toString() + "px";
    myImg.style.height = mySize.toString() + "px";
}
setInterval(zoomout, 100);