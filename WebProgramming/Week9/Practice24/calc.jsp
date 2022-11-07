<%-- 컴퓨터학과 20210815 주현정--%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Calculator</title>
    
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
                <form method=post action="calc_result.jsp">
                <td>
                    <input type ="text" name="num1" value="0" class="nums" onclick="this.value=''">
                    <br>
                    <select name="operator">
                    	<option value="+" selected>+</option>
                    	<option value="-">-</option>
                    	<option value="*">*</option>
                    	<option value="/">/</option>
                    </select>
                    <br>
                    <input type ="text" name="num2" value="0" class="nums" onclick="this.value=''"><br>
                    <input type="submit" value="="><br>
                    <input type ="text" disabled class="nums">
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