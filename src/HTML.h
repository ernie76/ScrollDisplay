#pragma once

const char* animationStartHTML = "<label for='animationStart'>Animation Start</label><br/>\
<select name='animationStart' id='animationStart' style='border-radius: .3rem;width: 100%; padding: 5px;font-size: 1em;margin: 5px 0; box-sizing: border-box;' onchange=\"if (this.selectedIndex==6){document.getElementById('spriteStartBlock').style.display = 'block'} else {document.getElementById('spriteStartBlock').style.display = 'none'}\")>\
<!--<option value='0'>PA_NO_EFFECT</option>-->\
<option value='1'>PA_PRINT</option>\
<option value='2'>PA_SCROLL_UP</option>\
<option value='3'>PA_SCROLL_DOWN</option>\
<option value='4' selected>PA_SCROLL_LEFT</option>\
<option value='5'>PA_SCROLL_RIGHT</option>\
<option value='6'>PA_SPRITE</option>\
<option value='7'>PA_SLICE</option>\
<option value='8'>PA_MESH</option>\
<option value='9'>PA_FADE</option>\
<option value='10'>PA_DISSOLVE</option>\
<option value='11'>PA_BLINDS</option>\
<option value='12'>PA_RANDOM</option>\
<option value='13'>PA_WIPE</option>\
<option value='14'>PA_WIPE_CURSOR</option>\
<option value='15'>PA_SCAN_HORIZ</option>\
<option value='16'>PA_SCAN_HORIZX</option>\
<option value='17'>PA_SCAN_VERT</option>\
<option value='18'>PA_SCAN_VERTX</option>\
<option value='19'>PA_OPENING</option>\
<option value='20'>PA_OPENING_CURSOR</option>\
<option value='21'>PA_CLOSING</option>\
<option value='22'>PA_CLOSING_CURSOR</option>\
<option value='23'>PA_SCROLL_UP_LEFT</option>\
<option value='24'>PA_SCROLL_UP_RIGHT</option>\
<option value='25'>PA_SCROLL_DOWN_LEFT</option>\
<option value='26'>PA_SCROLL_DOWN_RIGHT</option>\
<option value='27'>PA_GROW_UP</option>\
<option value='28'>PA_GROW_DOWN</option>\
</select><br>";

const char* animationEndeHTML = "<label for='animationEnde'>Animation Ende</label><br/>\
<select name='animationEnde' id='animationEnde' style='border-radius: .3rem;width: 100%; padding: 5px;font-size: 1em;margin: 5px 0; box-sizing: border-box;' onchange=\"if (this.selectedIndex==6){document.getElementById('spriteEndeBlock').style.display = 'block'} else {document.getElementById('spriteEndeBlock').style.display = 'none'}\")>\
<option value='0'>PA_NO_EFFECT</option>\
<option value='1'>PA_PRINT</option>\
<option value='2'>PA_SCROLL_UP</option>\
<option value='3'>PA_SCROLL_DOWN</option>\
<option value='4' selected>PA_SCROLL_LEFT</option>\
<option value='5'>PA_SCROLL_RIGHT</option>\
<option value='6'>PA_SPRITE</option>\
<option value='7'>PA_SLICE</option>\
<option value='8'>PA_MESH</option>\
<option value='9'>PA_FADE</option>\
<option value='10'>PA_DISSOLVE</option>\
<option value='11'>PA_BLINDS</option>\
<option value='12'>PA_RANDOM</option>\
<option value='13'>PA_WIPE</option>\
<option value='14'>PA_WIPE_CURSOR</option>\
<option value='15'>PA_SCAN_HORIZ</option>\
<option value='16'>PA_SCAN_HORIZX</option>\
<option value='17'>PA_SCAN_VERT</option>\
<option value='18'>PA_SCAN_VERTX</option>\
<option value='19'>PA_OPENING</option>\
<option value='20'>PA_OPENING_CURSOR</option>\
<option value='21'>PA_CLOSING</option>\
<option value='22'>PA_CLOSING_CURSOR</option>\
<option value='23'>PA_SCROLL_UP_LEFT</option>\
<option value='24'>PA_SCROLL_UP_RIGHT</option>\
<option value='25'>PA_SCROLL_DOWN_LEFT</option>\
<option value='26'>PA_SCROLL_DOWN_RIGHT</option>\
<option value='27'>PA_GROW_UP</option>\
<option value='28'>PA_GROW_DOWN</option>\
</select><br>";

const char* spriteStartHTML = "<span id='spriteStartBlock' style='display: none'><label for='spriteStart'>Sprite Start</label><br/>\
<select name='spriteStart' id='spriteStart' style='border-radius: .3rem;width: 100%; padding: 5px;font-size: 1em;margin: 5px 0; box-sizing: border-box;'>\
</select><br> \
<canvas id='spriteStartCanvas' width='200' height='100' style='border:1px solid #d3d3d3;'>\
Your browser does not support the HTML5 canvas tag.</canvas></span>";

const char* spriteEndeHTML = "<span id='spriteEndeBlock' style='display: none'><label for='spriteEnde'>Sprite Ende</label><br/>\
<select name='spriteEnde' id='spriteEnde' style='border-radius: .3rem;width: 100%; padding: 5px;font-size: 1em;margin: 5px 0; box-sizing: border-box;'>\
</select><br>\
<canvas id='spriteEndeCanvas' width='200' height='100' style='border:1px solid #d3d3d3;'>\
Your browser does not support the HTML5 canvas tag.</canvas></span>";

const char* javascript = "var animationnr = [0,0];\
var x = [10,10];\
var y = [80,80];\
var warte = [0,0];\
var sprite = [0,0];\
var hex_ani = [0,0];\
var requestID = [undefined,undefined];\
\
\
  var selStart = document.getElementById('spriteStart');\
  selStart.onchange = function(){spritewechsel(this.value,0)};\
  var selEnde = document.getElementById('spriteEnde');\
  selEnde.onchange = function(){spritewechsel(this.value,1)};\
\
  spritewechsel(0,0);\
  spritewechsel(0,1);\
\
function spritewechsel (element,zustand)  {\
    animationnr[zustand] = 0;\
    x[zustand] = 10;\
    y[zustand] = 80;\
    if (requestID[zustand]) {\
      cancelAnimationFrame(requestID[zustand]);\
      requestID[zustand] = undefined;\
    } \
    sprite[zustand] = allesprites[element];\
    var splitten = '.{1,'+ 2*sprite[zustand][2] + '}';\
    var re = new RegExp(splitten, 'g');\
    hex_ani[zustand] = sprite[zustand][3].match(re);\
    if (zustand == 0) {\
        animate0();\
    }\
    if (zustand == 1) {\
        animate1();\
    }\
  }\
\
function animate0 () {\
    requestID[0] = requestAnimationFrame(animate0);\
    render0(); \
}\
function animate1 () {\
    requestID[1] = requestAnimationFrame(animate1);\
    render1(); \
}\
\
function render0 () {\
    var c = document.getElementById('spriteStartCanvas');\
    var ctx = c.getContext('2d');\
    ctx.fillStyle = '#FF0000';\
    ctx.clearRect(0, 0, 200, 100);\
    x[0] = 10;\
    y[0] = 80;\
    var hex = hex_ani[0][animationnr[0]].match(/.{1,2}/g);\
    var bin;\
    for (h = 0; h < hex.length; h++) {\
       bin = hex2bin(hex[h]).split('');\
       for (i = 0; i < bin.length; i++) {\
        \
        if (bin[i]==1) {\
          ctx.fillRect(x[0],y[0],10,10);\
        } else {\
          ctx.fillRect(x[0],y[0],0,0);\
        }\
        y[0]-=10;\
      }\
      x[0]+=10;\
      y[0]=80;\
    }\
    ctx.stroke();\
    warte[0]++;\
    if (warte[0] > 10) {\
      warte[0] = 0;\
      animationnr[0] = animationnr[0] + 1; \
      if (animationnr[0] > hex_ani[0].length-1) { animationnr[0] = 0;}\
    }\
}\
\
function render1 () {\
    var c = document.getElementById('spriteEndeCanvas');\
    var ctx = c.getContext('2d');\
    ctx.fillStyle = '#FF0000';\
    ctx.clearRect(0, 0, 200, 100);\
    x[1] = 10;\
    y[1] = 80;\
    var hex = hex_ani[1][animationnr[1]].match(/.{1,2}/g);\
    var bin;\
    for (h = 0; h < hex.length; h++) {\
       bin = hex2bin(hex[h]).split('');\
       for (i = 0; i < bin.length; i++) {\
        \
        if (bin[i]==1) {\
          ctx.fillRect(x[1],y[1],10,10);\
        } else {\
          ctx.fillRect(x[1],y[1],0,0);\
        }\
        y[1]-=10;\
      }\
      x[1]+=10;\
      y[1]=80;\
    }\
    ctx.stroke();\
    warte[1]++;\
    if (warte[1] > 10) {\
      warte[1] = 0;\
      animationnr[1] = animationnr[1] + 1; \
      if (animationnr[1] > hex_ani[1].length-1) { animationnr[1] = 0;}\
    }\
}\
\
\
function hex2bin(hex){\
    return (parseInt(hex, 16).toString(2)).padStart(8, '0');\
}";

const char* intensityHTML = "<label for='intensity'>Helligkeit <span id='intensityValue'></span></label><br/>\
<input type='range' min='0' max='15' value='0' class='slider' id='intensity' name='intensity'>\
<script>\
var slider = document.getElementById('intensity');\
var output = document.getElementById('intensityValue');\
output.innerHTML = slider.value;\
slider.oninput = function() {\
    output.innerHTML = this.value;\
}\
</script>\
<br>";

const char* timeHTML = "<input type='hidden' id='timestamp' value=''name='timestamp'>\
<script>var d = new Date(); document.getElementById('timestamp').value = Math.floor(d.getTime() / 1000) - (d.getTimezoneOffset()*60); </script>";

const char* menueHTML = "<label for='textAnzeige' onclick='extramenu();'>Anzeige</label><br/>\
<select name='textAnzeige' id='textAnzeige' style='border-radius: .3rem;width: 100%; padding: 5px;font-size: 1em;margin: 5px 0; box-sizing: border-box;' onchange=\"if (this.options[this.selectedIndex].value==99){document.getElementById('playlistmenuHTML').style.display = 'block'} else {document.getElementById('playlistmenuHTML').style.display = 'none'}\">\
<option value='0'>Scrolltext</option>\
<option value='1'>Temperatur und Feuchtigkeit</option>\
<option value='2'>Uhr</option>\
<option value='3'>Uhr und Datum</option>\
<option value='4'>Game of Life</option>\
<option value='5'>Datum</option>\
<option value='6'>Monat</option>\
<option value='7'>Wochentag</option>\
<option value='99'>Playlist</option>\
</select><br>";

const char* automatikHTML = "\n\
<script type=\"text/javascript\">\n\
	autozaehler=1;\n\
	function dazu() {\n\
		autozaehler++;\n\
	document.getElementById('automatikneu').outerHTML = '\\\n\
			<span id=\"automatikspan'+autozaehler+'\">\\\n\
			<br>\\\n\
  <div style=\"width:60%; float:left;\">\\\n\
	<select name=\"automatik'+autozaehler+'\" id=\"automatik'+autozaehler+'\" size=\"1\" style=\"border-radius: .3rem;width: 100%; padding: 5px;font-size: 1em;margin: 5px 0; box-sizing: border-box;\" >\\\n\
		<option value=\"0\">Scrolltext</option>\\\n\
		<option value=\"1\">Temperatur</option>\\\n\
		<option value=\"2\">Uhr</option>\\\n\
		<option value=\"3\">Uhr und Datum</option>\\\n\
		<option value=\"4\">Game of Life</option>\\\n\
		<option value=\"5\">Datum</option>\\\n\
		<option value=\"6\">Monat</option>\\\n\
		<option value=\"7\">Wochentag</option>\\\n\
	</select>\\\n\
  </div>\\\n\
  <div style=\"width:30%; float:right;\">\\\n\
    <input name=\"automatikzeit'+autozaehler+'\" id=\"automatikzeit'+autozaehler+'\"  type=\"number\" min=\"1\" max=\"255\" step=\"1\" maxlength=\"100\" value=\"1\" placeholder=\"1\" style=\"border-radius: .3rem;width: 100%; padding: 0px;font-size: 1em;margin: 5px 0; box-sizing: border-box;\">\\\n\
  </div>\\\n\
	</span>\\\n\
	<span id=\"automatikneu\"></span>\\\n\
';\n\
		document.getElementById('autozaehler').value = autozaehler;\n\
	}\n\
	function weniger() {\n\
		document.getElementById('automatikspan'+autozaehler).outerHTML = '';\n\
		autozaehler--;\n\
		document.getElementById('autozaehler').value = autozaehler;\n\
	}\n\
</script>\n\
<div id='playlistmenuHTML' style='display: none'>\n\
  <div>\n\
	<input type=\"button\" value=\"+\" onclick=\"dazu()\" style=\"width:40%;float:left;\">\
  <input type=\"button\" value=\"-\" onclick=\"weniger()\" style=\"width:40%;float:right;\">\n\
  </div>\n\
  <div>\n\
	<div style=\"width:40%;float:left;\">Ereigniss</div>\
  <div style=\"width:40%;float:right;\">Sekunden</div>\n\
  </div>\n\
  <div style=\"width:60%; float:left;\">\n\
	<select name=\"automatik1\" id=\"automatik1\" size=\"1\" style=\"border-radius: .3rem;width: 100%; padding: 5px;font-size: 1em;margin: 5px 0; box-sizing: border-box;\" >\n\
		<option value=\"0\">Scrolltext</option>\n\
		<option value=\"1\">Temperatur</option>\n\
		<option value=\"2\">Uhr</option>\n\
		<option value=\"3\">Uhr und Datum</option>\n\
		<option value=\"4\">Game of Life</option>\n\
		<option value=\"5\">Datum</option>\n\
		<option value=\"6\">Monat</option>\n\
		<option value=\"7\">Wochentag</option>\n\
	</select>\n\
  </div>\n\
  <div style=\"width:30%; float:right;\">\n\
    <input id=\"automatikzeit1\" name=\"automatikzeit1\" type=\"number\" min=\"1\" max=\"255\" step=\"1\" maxlength=\"100\" value=\"1\" placeholder=\"1\" style=\"border-radius: .3rem;width: 100%; padding: 0px;font-size: 1em;margin: 5px 0; box-sizing: border-box;\">\n\
  </div>\n\
	<span id=\"automatikneu\"></span>\n\
 <input type=\"hidden\" id=\"autozaehler\" value=\"1\" name=\"autozaehler\">\n\
 </div>\n\
\n\
";

const char* extramenueHTML = "<div id='extramenue' style='display: none'><br><label for='extramenue'>Extra Menü</label><br/>\
<br>\
<label for='firmware'>Firmware</label>\
<select name='firmware' id='firmware' style='border-radius: .3rem;width: 100%; padding: 5px;font-size: 1em;margin: 5px 0; box-sizing: border-box;'>\
<option value='0'></option>\
<option value='1'>Stable</option>\
<option value='2'>Beta</option>\
<option value='3'>Experimental</option>\
</select><br>\
<label for='wlanssid'>Wlanssid</label>\
<input type='text' name='wlanssid' id='wlanssid' style='border-radius: .3rem;width: 100%; padding: 5px;font-size: 1em;margin: 5px 0; box-sizing: border-box;'>\
<br>\
<label for='wlanpassword'>Wlanpassword (wichtig mindestens 8 Zeichen!)</label>\
<input type='text' name='wlanpassword' id='wlanpassword' style='border-radius: .3rem;width: 100%; padding: 5px;font-size: 1em;margin: 5px 0; box-sizing: border-box;'>\
<br>\
<label for='xDisplays'>Display-Anzahl horizontal</label>\
<input type='text' name='xDisplays' id='xDisplays' style='border-radius: .3rem;width: 100%; padding: 5px;font-size: 1em;margin: 5px 0; box-sizing: border-box;' value='8'>\
<br>\
<label for='yDisplays'>Display-Anzahl vertikal</label>\
<input type='text' name='yDisplays' id='yDisplays' style='border-radius: .3rem;width: 100%; padding: 5px;font-size: 1em;margin: 5px 0; box-sizing: border-box;' value='1'>\
<br>\
<script>\
extra=0;\
function extramenu() {\
  extra++;\
  if (extra > 3) {\
    document.getElementById('extramenue').style.display='block';\
  }\
}\
</script>\
\
</div>";
