/* Application Sripts */
$(window).on("load", function () {
    setTimeout(function () {
        anim(0, document.getElementsByClassName("diapo"))
    }, 200);
});

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
    $.scrollify.update();
});
$(".respon").click(function(){
	$(".blog .t3").show();
	$(".blog .t2, .blog .t4").hide();
	$(this).removeClass("darken-2");
	$(".projects, .ideas").addClass("darken-2");
    $.scrollify.update();
});
$(".workexp").click(function(){
	$(".blog .t4").show();
	$(".blog .t3, .blog .t2").hide();
	$(this).removeClass("darken-2");
	$(".projects, .respon").addClass("darken-2");
    $.scrollify.update();
});

$(document).ready(function () {
	$(".about .t3, .about .t4, .blog .t3, .blog .t4").hide();
	$(".bio, .projects").toggleClass("darken-2");
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