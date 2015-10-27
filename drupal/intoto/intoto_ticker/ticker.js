/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {
    Drupal.behaviors.tooltips_behavior = {
		attach: function (context, settings) {
			$('.dont_show_link').click (function(event){
				event.preventDefault();

					selector = $(this);
					link = selector.attr("link");
				$.ajax({
				  url: link //"/ticker/1/remove-user?XDEBUG_SESSION_START=netbeans-xdebug",
		//	      beforeSend: function( xhr ) {
		//		//xhr.overrideMimeType( "text/plain; charset=x-user-defined" );
		//	      }
				})
				  .done(function( data ) {
				  if(data==="OK")
							{
								selector.closest("tr").fadeOut(500, function(){ $(this).remove();});
							}
				});	
			});

			$('.tooltip_field').each(function(){
				$(this).parent().attr('title', $(this).text());
			});

		}
	};
})(jQuery);
