const{Query,User}=AV;var exp=new Date();AV.init({	appId:"RI8ofTDRMRaaXNE6WyhrOhG8-MdYXbMMI",	appKey:"LQH5g6HnJWXeXmWwBUdO520f",	serverURL:"https://ri8oftdr.api.lncldglobal.com"});
const Todo = AV.Object.extend('ToWpz');
function liuy(){
	const todo = new Todo();
	todo.set('name', fan.na.value);
	todo.set('content', fan.co.value);
	todo.save().then((todo) => {
		alert("反馈成功！")
	}, (error) => {
		alert("反馈失败！请重试！");
	});
	return false;
}

const { Query, User } = AV;
AV.init({
  appId: "vY0rOSNHEeF8i9onQQhUAbiq-MdYXbMMI",
  appKey: "30mnYsEf5kuRef290IakWTSb",
  serverURL: "https://vy0rosnh.api.lncldglobal.com"
});
const Counter = new AV.Query("Counter");
Counter.get('62ca99405f903a0feb65d1d1').then((Counter) => {
  if(document.cookie.indexOf("count=true")==-1){
    Counter.set("Data",Counter.get("Data")+1);
    Counter.save();
    document.cookie="count=true";
  }
  document.getElementById("SiteCounter").innerHTML="你是第"+Counter.get("Data")+"个访问本站的人";
  
});