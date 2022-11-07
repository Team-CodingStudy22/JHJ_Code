<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 <%!
 	int num1, num2 = 0;
 	String op = "+";
 	
 	public int calculator() {
 		int result = 0;
 		
 		if(op.equals("+"))
 			result = num1 + num2;
 		else if(op.equals("-"))
 			result = num1 - num2;
 		else if(op.equals("*"))
 			result = num1 * num2;
 		else if(op.equals("/"))
 			result = num1 / num2;
 		
 		return result;
 	}
 %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Calculator Result</title>
<style>
        table, td {
            text-align: center;
            font-size: 30px;
            width: 450px;
            height: 300px;
        }
        
        td {
            border : solid 1px #EDECED;
        }
        
        .blue {
            background-color: #33CCFE;
            height: 50px;
        }
        
        .nums {
        	width:100px;
            text-align: center;
        }
        
        .nonums {
        	border:0px;
        	text-align: center;
        }
        
        img {
            width: 230px;
            height: 300px;
        }
    </style>
    
</head>
<body>
<%
	String sNum1 = request.getParameter("num1");
	num1 = Integer.parseInt(sNum1);
	String sNum2 = request.getParameter("num2");
	num2 = Integer.parseInt(sNum2);
	
	op = request.getParameter("operator");
%>
    <div align = "center">
        <table>
            <tr>
                <td colspan = "2" class = "blue" style=" font: italic 1.5em/1em Georgia, serif ;">CalCuLaTor</td>
            </tr>
            
            <tr>
                <td>
                    <img src = "image/cal.jpg">
                </td>
                <form>
                <td>
                    <input type ="text" <%out.println("value=\"" + num1 + "\""); %> class="nums" readonly>
                    <br>
                    <input type ="text" <%out.println("value=\"" + op + "\""); %> class="nonums" readonly>
                    <br>
                    <input type ="text" <%out.println("value=\"" + num2 + "\""); %> class="nums" readonly>
                    <br>
                    <input type ="text" value="=" class="nonums" readonly>
                    <br>
                    <input type ="text" <%out.println("value=\"" + calculator() + "\""); %> class="nums">
                </td>
                </form>
            </tr>
            
            <tr>
                <td class = "blue" colspan = "2"></td>
            </tr>
        </table>
    </div>
</body>
</html>