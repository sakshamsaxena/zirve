/* Application Sripts */

$(document).ready(function() {
    $(".home .t1, .home .t2, .home .t3, .home .t4").css("opacity", "0");
    $(".about .t3, .about .t4, .proj .t3, .proj .t4").hide();
    $(".bio, .projects").toggleClass("darken-2");
});

$(window).on("load", function() {
    setTimeout(function() {
        anim(0, document.getElementsByClassName("diapo"))
    }, 200);
    if(window.innerWidth < 768){
        $.scrollify.destroy();
        $(".diapo").css("height", window.innerHeight+60);
        $(".starter-template").css("height", window.innerHeight-100)
        $(".proj .row span.col-xs-4").attr("class","row");
        $(".socialHome span").each(function(i,el) {
            if($(this).hasClass("col-xs-3"))
                $(this).remove();
            if($(this).hasClass("col-xs-1"))
                $(this).attr("class", "col-xs-2");
        })
    }
});

$(function() {
    if(window.innerWidth >= 768)
        $.scrollify({
            section: ".diapo",
            scrollbars: true,
            overflowScroll: true,
            touchScroll: false,
            after: function(i, panels) {
                anim(i, panels)
            }
        });
});

// Handlers for Home Page
$(".aboutBtn, .contBtn, .projBtn").click(function(e) {
    //TODO : Write custom jQ style smooth scroll
    if(window.innerWidth > 768) {
        $.scrollify.move(e.target.getAttribute("href"));
    }
    return true
});

// TODO : Update height for ALL diapo on click
// Handlers for About Page
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

// Handlers for Work Exp Page
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

// Helper Functions
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