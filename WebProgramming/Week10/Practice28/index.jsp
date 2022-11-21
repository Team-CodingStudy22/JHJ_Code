   <%--20210815 컴퓨터학과 주현정 --%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>index</title>

<style>
h2 {
	text-align:center;
}

table {
	border : 0;
}
</style>
</head>
<body>
<h2>Alice in Wonderland</h2>
<div align=center>
<table border="0">
<tr height = "50px">
	<td width="10px">
		<jsp:include page="viewer.jsp"/>
	</td>
	<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
	<td>
		<jsp:include page="login.jsp"/>
	</td>
</tr>
</table>
</div>
</body>
</html>