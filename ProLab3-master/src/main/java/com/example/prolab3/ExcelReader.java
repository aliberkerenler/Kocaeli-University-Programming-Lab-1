package com.example.prolab3;


import org.apache.poi.ss.usermodel.*;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.*;

public class ExcelReader {
    public static List<Map<String, String>> readExcel(String filePath) throws IOException {
        FileInputStream fis = new FileInputStream(new File(filePath));
        Workbook workbook = new XSSFWorkbook(fis);
        Sheet sheet = workbook.getSheetAt(0);
        Iterator<Row> rowIterator = sheet.iterator();
        List<Map<String, String>> authorsList = new ArrayList<>();

        // Assuming the first row is the header
        rowIterator.next(); // Skip header row

        while (rowIterator.hasNext()) {
            Row row = rowIterator.next();
            Map<String, String> authorData = new HashMap<>();
            authorData.put("title", row.getCell(0).getStringCellValue()); // Makale adı
            authorData.put("coAuthors", row.getCell(1).getStringCellValue()); // Yazarlar
            authorData.put("doi", row.getCell(2).getStringCellValue()); // DOI

            authorsList.add(authorData);
        }

        workbook.close();
        return authorsList;
    }
}

