<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:template match="/students">
        <html>
        <head>
            <title>Аттестация студентов</title>
            <style>
                table {
                    border-collapse: collapse;
                }
                th, td {
                    border: 1px solid black;
                    text-align: center;
                    padding: 5px;
                }
                .low-grade {
                    background-color: red;
                    color: white;
                }
                .high-grade {
                    background-color: green;
                    color: white;
                }
            </style>
        </head>
        <body>
            <h1>Результаты аттестации</h1>
            <table>
                <!-- Заголовок таблицы -->
                <tr>
                    <th>Студент</th>
                    <xsl:for-each select="student[1]/grades/subject">
                        <th><xsl:value-of select="@name"/></th>
                    </xsl:for-each>
                </tr>

                <xsl:for-each select="student">
                    <tr>
                        <td><xsl:value-of select="name"/></td>
                        <xsl:for-each select="grades/subject">
                            <td>
                                <xsl:attribute name="class">
                                    <xsl:choose>
                                        <xsl:when test=". &lt; 4">low-grade</xsl:when>
                                        <xsl:when test=". &gt; 8">high-grade</xsl:when>
                                    </xsl:choose>
                                </xsl:attribute>
                                <xsl:value-of select="."/>
                            </td>
                        </xsl:for-each>
                    </tr>
                </xsl:for-each>
            </table>
        </body>
        </html>
    </xsl:template>
</xsl:stylesheet>
