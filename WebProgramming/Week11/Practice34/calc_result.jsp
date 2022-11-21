<%-- 컴퓨터학과 20210815 주현정--%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="jspbook.pr34.*"%>
<jsp:useBean id="calc" class="jspbook.pr34.Calculator" scope="page" />
<jsp:setProperty name="calc" property="*" />
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
                    <input type ="text" value = "<%out.println(calc.getOp1()); %>" class="nums" readonly>
                    <br>
                    <input type ="text" value = "<%out.println(calc.getOperator()); %>" class="nonums" readonly>
                    <br>
                    <input type ="text" value = "<%out.println(calc.getOp2()); %>" class="nums" readonly>
                    <br>
                    <input type ="text" value="=" class="nonums" readonly>
                    <br>
                    <input type ="text" value = "<%out.println(calc.calc()); %>" class="nums">
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