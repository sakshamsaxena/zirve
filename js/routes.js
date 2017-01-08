// Permanent Blog Post Link Management Script

// URL scheme : /blog/index.html?postId=N
// where N is the postId

$(window).on("load", function () {
	var postId = window.location.search;
	postId = postId.substr(8, postId.length);
	var postURL = 'http://localhost:3000/blog/posts/' + postId;
	$.ajax({
		method: 'GET',
		url: postURL,
		success: function (data) {
			// Get the data in right format
			var post = data[0];
			var title = post.title;
			var content = post.content;
			
			// Put the data now
			$("#post-title").text(title);
			$(".latest-blog-gist").html(content);
		}
	})
})
