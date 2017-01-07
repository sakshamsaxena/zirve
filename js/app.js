/* Application Sripts */
function drag_start(event) {
	event.originalEvent.dataTransfer.setData("text/plain", (event.pageX) + ',' + (event.pageY));
}

function drag_over(event) {
	event.preventDefault();
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

$("#dragme").on("dragstart", drag_start).click(function () {
	$("section.menu").slideToggle();
});

$(".menu ul.collection .title").click(function(e) {
	$("section.menu").slideToggle();
	$.scrollify.move(e.target.getAttribute("href"));
	return true
})

$("body").on("dragover", drag_over);

$("body").on("drop", drop);

$(document).ready(function () {
	setTimeout(function () {
		anim(0, document.getElementsByClassName("diapo"));
	}, 200)
})

$(function () {
	$.scrollify({
		section: ".diapo",
		scrollbars: false,
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
			console.log($(panels[i]).find(".t1"))
		}
	});

	$(".pagination a").on("click", $.scrollify.move);
});
