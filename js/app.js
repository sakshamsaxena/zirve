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
		duration: 1000,
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
		url: 'https://localhost:3000/blog/latest',
		success: function (data) {
			// Get the data in right format
			var post = data[0];
			var title = post.title;
			var content = post.content;
			var fullURL = "https://localhost:80/blog/#" + post.postId;
			content = content.substr(0, 190);
			content = content.substr(0, content.lastIndexOf(" "));
			content += " ...";

			// Put the data now
			$("#post-title").text(title).parent().attr("href", fullURL);
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

$(document).ready(function () {
	var ht = (window.innerHeight > 500) ? 400 : window.innerHeight;
	$(".blog-scroll").css("height", ht+"px")
});

$(window).on("load", function () {
	setTimeout(function () {
		anim(0, document.getElementsByClassName("diapo"))
	}, 200);
	getLatestPost()
});

$(function () {
	var flag;
	window.innerWidth <= 768 ? flag = true : flag = false;
	console.log(flag);
	$.scrollify({
		section: ".diapo",
		scrollbars: flag,
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
