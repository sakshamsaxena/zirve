var Keys = Object.keys(List);
var Length = Keys.length;
var LastKey = (Keys[Length - 1]);
var LastArray = List[LastKey];
var LastArrayLength = LastArray.length;
var LastArrayLastObject = LastArray[LastArrayLength - 1];
var Pending = [];

function populate(li) {
	console.log("Populating HTML ...");
	var flag;
	for (var item in li) {
		var title = item;
		var html = '';
		flag = 1;
		html += makeHeader(title);
		var arr = li[item];
		for (var i = 0; i < arr.length; i++) {
			var o = arr[i];
			if (o.code) {
				html += makeBody(i + 1, o.url, o.name, o.code);
				flag = 0;
			} else {
				Pending.push(item + " : " + o.name);
			}
		}
		if (flag == 0)
			$("div.home").append(html + '</div>');
	}
	$("#loader").remove();
	console.log(Pending);
}

function makeHeader(title) {
	return '<div class="t3"><h2 class="t1">' + title + '</h2>'
}

function makeBody(num, url, prob_title, code) {
	return '<p class="lead"><strong>' + num + '. <a href="' + url + '">' + prob_title + '</a></strong><pre>' + code + '</pre></p>'
}

function makeRequest(Item, index) {
	var foldername = Item;
	while(foldername !== foldername.toString().replace(" ", "")) {
		foldername = foldername.toString().replace(" ", "");
	}
	var url = '/solutions/' + foldername + '/' + index + '.cpp';
	var p = parseInt(index) - 1;
	$.ajax({
		url: url,
		success: function(data) {
			var d = data;
			while (d !== d.replace("<", "&lt;")) {
				d = d.replace("<", "&lt;");
			}
			while (d !== d.replace(">", "&gt;")) {
				d = d.replace(">", "&gt;");
			}
			while (d !== d.replace("\t", "&nbsp;&nbsp;&nbsp;&nbsp;")) {
				d = d.replace("\t", "&nbsp;&nbsp;&nbsp;&nbsp;");
			}
			while (d !== d.replace("\r\n", "<br>")) {
				d = d.replace("\r\n", "<br>");
			}
			while (d !== d.replace("\n", "<br>")) {
				d = d.replace("\n", "<br>");
			}
			(List[Item])[p].code = d;
			console.log("Loaded : " + url);
		},
		error: function() {
			console.log('Not Found : ' + url);
		},
		complete: function() {
			if (foldername === LastKey.replace(" ", "") && index === LastArrayLength) {
				populate(List);
			}
		}
	})
}

for (var Item in List) {
	var arr = List[Item];
	for (var k = 0; k < arr.length; k++) {
		var obj = arr[k];
		var index = k + 1;
		makeRequest(Item, index);
	}
}