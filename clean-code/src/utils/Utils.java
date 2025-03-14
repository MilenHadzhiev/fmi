package utils;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Utils {
    private static final Logger logger = LoggerFactory.getLogger(Utils.class);

    public static Date parseStringToDate(String string) throws ParseException {
        String[] dateFormats = {"yyyy-MM-dd", "dd-MM-yyyy", "MM/dd/yyyy"};

        for (String dateFormat : dateFormats) {
            try {
                return new SimpleDateFormat(dateFormat).parse(string);
            } catch (ParseException e) {
                logger.debug(e.getMessage());
            }
        }
        throw new ParseException("Supported date formats: " + Arrays.toString(dateFormats) + ". String: " + string, 0);
    }
}
