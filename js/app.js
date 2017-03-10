/* Application Sripts */
function drag_start(event) {
	event.originalEvent.dataTransfer.setData("text/plain", (event.pageX) + ',' + (event.pageY));
	console.log("Start")
}

function drag_over(event) {
	event.preventDefault();
	console.log("Over-ring")
	return false;
}

function drop(event) {
	var d = event.originalEvent.dataTransfer.getData("text/plain").split(',');
	var oldX = parseInt(d[0]);
	var oldY = parseInt(d[1]);

	var dm = $("#dragme");
	var offsetX = dm.offset().left;
	var offsetY = dm.offset().top;

	var top = parseFloat(event.pageY - oldY + offsetY);
	var left = parseFloat(event.pageX - oldX + offsetX);

	dm.offset({
		top: top,
		left: left
	});
	
	console.log("drop")
	event.preventDefault();
	return false;
}

function anim(i, panels) {
	var q = {
		opacity: 1
	};
	var r = {
		duration: 800,
		queue: true
	};

	$(panels[i]).find(".t1")
		.animate(q, r)
		.queue(function () {
			$(panels[i]).find(".t2").animate(q, r);
			$(this).dequeue();
		})
		.delay(2000)
		.queue(function () {
			$(panels[i]).find(".t3").animate(q, r);
			$(this).dequeue();
		})
		.delay(1500)
		.queue(function () {
			$(panels[i]).find(".t4").animate(q, r);
			$(this).dequeue();
		});
}

function getLatestPost() {
	$.ajax({
		method: 'GET',
		url: 'http://localhost:3000/blog/latest',
		success: function (data) {
			// Get the data in right format
			var post = data[0];
			var title = post.title;
			var content = post.content;
			var fullURL = "blog/index.html?postId=" + post.postId;
			content = content.substr(0, 190);
			content = content.substr(0, content.lastIndexOf(" "));
			content += " ...";

			// Put the data now
			$("#post-title").text(title).parent().attr("href", fullURL);
			$("#readMore").attr("href", fullURL);
			$(".latest-blog-gist").html(content);
		}
	})
}

function populateBlogSection() {
	//TODO : Get posts number, make accordingly the rows and cols, and append!
}

$("body").on("dragover", drag_over);

$("body").on("drop", drop);

$("#dragme").on("dragstart", drag_start).click(function () {
	$("section.menu").slideToggle();
});

$(".menu ul.collection .title").click(function (e) {
	$("section.menu").slideToggle();
	$.scrollify.move(e.target.getAttribute("href"));
	return true
});

$(".aboutBtn, .contBtn, .projBtn").click(function (e) {
	$.scrollify.move(e.target.getAttribute("href"));
	return true
});

$(".bio").click(function(){
	$(".about .t2").show();
	$(".about .t3, .about .t4").hide();
	$(this).removeClass("darken-2");
	$(".interests, .ideas").addClass("darken-2");
});
$(".interests").click(function(){
	$(".about .t3").show();
	$(".about .t2, .about .t4").hide();
	$(this).removeClass("darken-2");
	$(".bio, .ideas").addClass("darken-2");
});
$(".ideas").click(function(){
	$(".about .t4").show();
	$(".about .t3, .about .t2").hide();
	$(this).removeClass("darken-2");
	$(".bio, .interests").addClass("darken-2");
});

$(".projects").click(function(){
	$(".blog .t2").show();
	$(".blog .t3, .blog .t4").hide();
	$(this).removeClass("darken-2");
	$(".respon, .workexp").addClass("darken-2");
});
$(".respon").click(function(){
	$(".blog .t3").show();
	$(".blog .t2, .blog .t4").hide();
	$(this).removeClass("darken-2");
	$(".projects, .ideas").addClass("darken-2");
});
$(".workexp").click(function(){
	$(".blog .t4").show();
	$(".blog .t3, .blog .t2").hide();
	$(this).removeClass("darken-2");
	$(".projects, .respon").addClass("darken-2");
});

$(document).ready(function () {
	var ht = (window.innerHeight > 500) ? 400 : window.innerHeight;
	$(".blog-scroll").css("height", ht+"px");
	$(".about .t3, .about .t4, .blog .t3, .blog .t4").hide();
	$(".bio, .projects").toggleClass("darken-2");
});

$(window).on("load", function () {
	setTimeout(function () {
		anim(0, document.getElementsByClassName("diapo"))
	}, 200);
	getLatestPost()
});

$(function () {
	$.scrollify({
		section: ".diapo",
		scrollbars: true,
		overflowScroll: true,
		touchScroll: true,
		afterRender: function () {
			var pagination = "<ul class=\"pagination\">";
			var activeClass = "";
			$(".diapo").each(function (i) {
				activeClass = "";
				if (i === 0) {
					activeClass = "active";
				}
				pagination += "<li><a class=\"" + activeClass + "\" href=\"#" + $(this).attr("data-section-name") + "\"><span class=\"hover-text\">" + $(this).attr("data-section-name").charAt(0).toUpperCase() + $(this).attr("data-section-name").slice(1) + "</span></a></li>";
			});

			pagination += "</ul>";

			$("body").append(pagination);
		},
		before: function (i, panels) {
			var ref = panels[i].attr("data-section-name");
			$(".pagination .active").removeClass("active");
			$(".pagination").find("a[href=\"#" + ref + "\"]").addClass("active");
		},
		after: function (i, panels) {
			anim(i, panels)
		}
	});

	$(".pagination a").on("click", $.scrollify.move);
});
