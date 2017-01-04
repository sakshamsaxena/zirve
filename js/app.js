/* Application Sripts */

(function () {
	function drag_start(event) {
		var style = window.getComputedStyle(event.target, null);
		event.dataTransfer.setData("text/plain", (parseInt(style.getPropertyValue("left"), 10) - event.clientX) + ',' + (parseInt(style.getPropertyValue("top"), 10) - event.clientY));
	}

	function drag_over(event) {
		event.preventDefault();
		return false;
	}

	function drop(event) {
		var offset = event.dataTransfer.getData("text/plain").split(',');
		var dm = document.getElementById('dragme');
		dm.style.left = (event.clientX + parseInt(offset[0], 10)) + 'px';
		dm.style.top = (event.clientY + parseInt(offset[1], 10)) + 'px';
		event.preventDefault();
		return false;
	}
	var dm = document.getElementById('dragme');
	dm.addEventListener('dragstart', drag_start, false);
	document.body.addEventListener('dragover', drag_over, false);
	document.body.addEventListener('drop', drop, false);
})();

$(function () {
	$.scrollify({
		section: ".diapo",
		scrollbars: false,
		before: function (i, panels) {
			var ref = panels[i].attr("data-section-name");
			$(".pagination .active").removeClass("active");
			$(".pagination").find("a[href=\"#" + ref + "\"]").addClass("active");
		},
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
		}
	});
	
	$(".pagination a").on("click", $.scrollify.move);
});
