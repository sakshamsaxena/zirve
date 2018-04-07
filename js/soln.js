var Keys = Object.keys(List);
var Length = Keys.length;
var LastKey = (Keys[Length-1]);
var LastArray = List[LastKey];
var LastArrayLength = LastArray.length;
var LastArrayLastObject = LastArray[LastArrayLength-1];

function populate(li) {
  var flag = 0;
  for(var item in li) {
    var title = item;
    var html = '';
    if(flag == 0)
      html+=makeHeader(title);
    var arr = li[item];
    for(var i = 0; i < arr.length; i++) {
      var o = arr[i];
      if(o.code) {
        html+=makeBody(i+1, o.url, o.name, o.code)
      } else {
        flag = 1;
        break;
      }
    }
    $("div.home").append(html);
  }
}

function makeHeader(title) {
  return '<div class="t3"><h2 class="t1">'+title+'</h2>'
}

function makeBody(num, url, prob_title, code) {
  return '<p class="lead"><strong>'+num+'. <a href="'+url+'">'+prob_title+'</a></strong><blockquote>'+code+'</blockquote></p></div>'
}

function makeRequest(foldername, index) {
  var url = './solutions/'+foldername+'/'+index+'.cpp';
  // console.log(url)
  var p = parseInt(index)-1;
  $.ajax({
    url: url,
    success: function (data) {
      var d = data;
      (List[foldername])[p].code = d;
    },
    error: function() {
      console.log('not found')
    },
    complete: function () {
      if(foldername === LastKey.replace(" ","") && index === LastArrayLength) {
        populate(List);
      }
    }
  })
}

for(var Item in List) {
  var foldername = Item.toString().replace(" ","");
  var arr = List[Item];
  for(var k = 0; k < arr.length; k++) {
    var obj = arr[k];
    var index = k+1;
    makeRequest(foldername, index);
  }
}
