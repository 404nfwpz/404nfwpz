var GetCounterData = {
  "url": "https://api.404nfwpz.tk/1.1/classes/Counter/62fe4e59ade0844a97a8b20d",
  "method": "GET",
  "timeout": 0,
  "headers": {
    "X-LC-Id": "vY0rOSNHEeF8i9onQQhUAbiq-MdYXbMMI",
    "X-LC-Key": "30mnYsEf5kuRef290IakWTSb",
    "Content-Type": "application/json"
  },
};
$.ajax(GetCounterData).done(function (response) {
  if(document.cookie.indexOf("count=true")==-1){
    var AddCounterData = {
      "url": "https://api.404nfwpz.tk/1.1/classes/Counter/62fe4e59ade0844a97a8b20d",
      "method": "PUT",
      "timeout": 0,
      "headers": {
        "X-LC-Id": "vY0rOSNHEeF8i9onQQhUAbiq-MdYXbMMI",
        "X-LC-Key": "30mnYsEf5kuRef290IakWTSb",
        "Content-Type": "application/json"
      },
      "data": JSON.stringify({
        "Data": {
          "__op": "Increment",
          "amount": 1
        }
      }),
    };
    $.ajax(AddCounterData).done(function () {
      document.cookie="count=true";
    });
  }
  document.getElementById("SiteCounter").innerHTML="你是第"+response.Data+"个访问本站的人";
});