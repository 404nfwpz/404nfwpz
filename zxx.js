var data = ['谢谢参与', '一等奖', '谢谢参与', '谢谢参与', '二等奖', '谢谢参与', '三等奖', '三等奖'],

 timer = null, //定时器

 flag = 0; //用于键盘事件状态标记

 

window.onload = function() {

 

 var play = document.getElementById('play'),

  stop = document.getElementById('stop');

 

 // 开始抽奖

 play.onclick = playFun;

 stop.onclick = stopFun;

 

 // 键盘事件

 document.onkeyup = function(event) {

  event = event || window.event;

  if (event.keyCode == 13) {

   if (flag == 0) {

    playFun();

    flag = 1;

   } else {

    stopFun();

    flag = 0;

   }

  }

 }

}

// 开始抽奖

function playFun() {

 var title = document.getElementById('title');

 var play = document.getElementById('play');

 //每次都先清除上一次的定时器任务，避免抽奖效果累加频率会越来越快

 clearInterval(timer);

 timer = setInterval(function() {

  var random = Math.floor(Math.random() * data.length);

  title.innerHTML = data[random];

 }, 50);

 play.style.background = '#999';

}

//停止抽奖

function stopFun() {

 clearInterval(timer);

 var play = document.getElementById('play');

 play.style.background = '#036';

}