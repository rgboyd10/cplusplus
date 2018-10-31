<html>
<body>

  <% 
    dim name 
    name = Request.QueryString("name")

    dim message
    message = "Hello, " + Server.HTmlEncode(name)
  %>

  <div>  
	<%= message %>   
  </div>

</body>
</html>


