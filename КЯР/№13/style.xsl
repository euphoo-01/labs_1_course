<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">


    <xsl:template match="/store">
        <html>
        <head>
            <title>Сортировка товаров</title>
        </head>
        <body>
            <h1>Список товаров</h1>
            <table border="1">
                <tr>
                    <th>Название</th>
                    <th>Категория</th>
                    <th>Описание</th>
                    <th>Наличие</th>
                    <th>Цена</th>
                </tr>
                <xsl:for-each select="product">
                    <xsl:sort select="number(translate(price, '$', ''))" order="ascending" />
                    <tr>
                        <td><xsl:value-of select="name" /></td>
                        <td><xsl:value-of select="category" /></td>
                        <td><xsl:value-of select="description" /></td>
                        <td><xsl:value-of select="availability" /></td>
                        <td><xsl:value-of select="price" /></td>
                    </tr>
                </xsl:for-each>
            </table>
        </body>
        </html>
    </xsl:template>
</xsl:stylesheet>
