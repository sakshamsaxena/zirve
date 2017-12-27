/* Application Sripts */
$(window).on("load", function() {
    setTimeout(function() {
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
        .queue(function() {
            $(panels[i]).find(".t2").animate(q, r);
            $(this).dequeue();
        })
        .delay(2000)
        .queue(function() {
            $(panels[i]).find(".t3").animate(q, r);
            $(this).dequeue();
        })
        .delay(1500)
        .queue(function() {
            $(panels[i]).find(".t4").animate(q, r);
            $(this).dequeue();
        });
}

$(".aboutBtn, .contBtn, .projBtn").click(function(e) {
    $.scrollify.move(e.target.getAttribute("href"));
    return true
});

$(".bio").click(function() {
    $(".about .t2").show();
    $(".about .t3, .about .t4").hide();
    $(this).removeClass("darken-2");
    $(".interests, .ideas").addClass("darken-2");
});
$(".interests").click(function() {
    $(".about .t3").show();
    $(".about .t2, .about .t4").hide();
    $(this).removeClass("darken-2");
    $(".bio, .ideas").addClass("darken-2");
});
$(".ideas").click(function() {
    $(".about .t4").show();
    $(".about .t3, .about .t2").hide();
    $(this).removeClass("darken-2");
    $(".bio, .interests").addClass("darken-2");
});

$(".projects").click(function() {
    $(".proj .t2").show();
    $(".proj .t3, .proj .t4").hide();
    $(this).removeClass("darken-2");
    $(".respon, .workexp").addClass("darken-2");
    $.scrollify.update();
});
$(".respon").click(function() {
    $(".proj .t3").show();
    $(".proj .t2, .proj .t4").hide();
    $(this).removeClass("darken-2");
    $(".projects, .ideas").addClass("darken-2");
    $.scrollify.update();
});
$(".workexp").click(function() {
    $(".proj .t4").show();
    $(".proj .t3, .proj .t2").hide();
    $(this).removeClass("darken-2");
    $(".projects, .respon").addClass("darken-2");
    $.scrollify.update();
});

$(document).ready(function() {
    $(".about .t3, .about .t4, .proj .t3, .proj .t4").hide();
    $(".bio, .projects").toggleClass("darken-2");
});

$(function() {
    $.scrollify({
        section: ".diapo",
        scrollbars: true,
        overflowScroll: true,
        touchScroll: true,
        after: function(i, panels) {
            anim(i, panels)
        }
    });

    $(".pagination a").on("click", $.scrollify.move);
});