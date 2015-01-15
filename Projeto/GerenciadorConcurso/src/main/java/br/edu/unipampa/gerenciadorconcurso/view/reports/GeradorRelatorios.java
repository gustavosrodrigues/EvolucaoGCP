/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.view.reports;

import br.edu.unipampa.gerenciadorconcurso.dao.HibernateUtil;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import net.sf.jasperreports.engine.JRException;
import net.sf.jasperreports.engine.JasperFillManager;
import net.sf.jasperreports.engine.JasperPrint;
import net.sf.jasperreports.view.JasperViewer;
import org.hibernate.Hibernate;
import org.hibernate.internal.SessionImpl;

/**
 *
 * @author Douglas
 */
public class GeradorRelatorios {

    @SuppressWarnings({"unchecked", "rawtypes"})
    public static void gerar(String nomeRel, ArrayList<Parametro> parametros) {
        JasperPrint rel = null;

        HashMap par = new HashMap();
        String arquivoJasper = (nomeRel); 
        
        if(parametros != null){
            for (Parametro param : parametros) {
                    String nome = param.getNome();
                    String valor = param.getValor();
                    par.put(nome, valor);
                }
        }
        try {        
            rel = JasperFillManager.fillReport(arquivoJasper, par, ((SessionImpl)HibernateUtil.openSession()).connection());
        } catch (JRException ex) {
            Logger.getLogger(GeradorRelatorios.class.getName()).log(Level.SEVERE, null, ex);
        }
        

        JasperViewer.viewReport(rel, false);

    }
}
