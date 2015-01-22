/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.validator;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * @author Douglas Giordano
 * @since 28/04/2013
 */
public class Data {

    /**
     * Verifica se a data é valida
     *
     * @param date
     * @return boolean
     */
    public static boolean isDateValid(String date) {
        SimpleDateFormat df = new SimpleDateFormat("dd-MM-yyyy");
        df.setLenient(false);
        try {
            df.parse(date);
            return true;
        } catch (ParseException ex) {
            return false;
        }
    }

    /**
     * Converte data string para data tipo date
     *
     * @param date
     * @return boolean
     */
    public static Date converteData(String date) {
        SimpleDateFormat df = new SimpleDateFormat("dd-MM-yyyy");
        df.setLenient(false);
        try {
            return df.parse(date);
        } catch (ParseException ex) {
            return null;
        }
    }

    /**
     * Converte uma hora String para date
     *
     * @param hora
     * @return Date formada
     */
    public static Date conveteHora(String hora) {
        SimpleDateFormat df = new SimpleDateFormat("HH:mm");
        df.setLenient(false);
        try {
            return df.parse(hora);
        } catch (ParseException ex) {
            //return null;
            return new Date();//Temp
        }
    }

    /**
     * Formata a data para o formato dd/mm/aaaa
     *
     * @param date
     * @return
     */
    public static String formatDate(String date) {
        String dataInicial = "";
        if (!(date.equalsIgnoreCase("null") || date.equalsIgnoreCase(""))) {
            dataInicial = date.substring(8, 10) + "-" + date.substring(5, 7) + "-" + date.substring(0, 4);
            date = dataInicial;
        }
        return dataInicial;
    }

    /**
     * Formata a data para o formato dd/mm/aaaa
     *
     * @param date
     * @return
     */
    public static String formatDateString(String date) {
        String dataInicial = "";
        if (!(date.equalsIgnoreCase("null") || date.equalsIgnoreCase(""))) {
            dataInicial = date.substring(0, 2) + "." + date.substring(3, 5) + "." + date.substring(6, 10);
            date = dataInicial;
        }
        return dataInicial;
    }

    /**
     * Formata a data para o formato dd/mm/aaaa
     *
     * @param date
     * @return data formatada
     */
    public static String formatDate(Date date) {
        SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
        try {
            return sdf.format(date);
        } catch (NullPointerException erro) {
            return "";
        }
    }

    /**
     * Retorna a data atual do computador.
     *
     * @return data atual
     */
    public static String dataAtual() {
        Date data = new Date();
        SimpleDateFormat formatador = new SimpleDateFormat("dd-MM-yyyy");
        return formatador.format(data);
    }

    public static String convertDataIsoSql(Date dataOld) {
        String data = formatDate(dataOld);
        String datanew = "";
        if (!(data.equalsIgnoreCase("null") || data.equalsIgnoreCase(""))) {
            datanew = data.substring(6, 10) + data.substring(3, 5) + data.substring(0, 2);
            data = datanew;
        }
        return datanew;
    }

    public static String convertDataIsoSql(String dataOld) {
        String data = dataOld;
        String datanew = "";
        if (!(data.equalsIgnoreCase("null") || data.equalsIgnoreCase(""))) {
            datanew = data.substring(6, 10) + data.substring(3, 5) + data.substring(0, 2);
            data = datanew;
        }
        return datanew;
    }
    
    /**
     * Retira os símbolos de uma data.
     * @param data
     * @return Data sem símbolos
     */
    public static String retirarSimbolosData(String data) {
        String dataFinal = "";
        for (int i = 0; i < data.length(); i++) {
            if (!(data.charAt(i) == '/') && !(data.charAt(i) == '-')) {
                dataFinal = dataFinal + data.charAt(i);
            }
        }
        if(dataFinal.equals("")){
            return null;
        }else{
            return dataFinal;
        }

    }
}
