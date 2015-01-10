/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.dao;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import org.hibernate.Criteria;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.criterion.Restrictions;

/**
 *
 * @author Douglas
 */
public class DAO {

    // <editor-fold defaultstate="collapsed" desc="INSERT and UPDATE"> 
    /**
     * Salva um objeto mapeado no banco de dados
     *
     * @param obj
     * @return boolean se salvou ou não
     */
    public static boolean salvar(Object obj) {
        Session session = HibernateUtil.openSession();
        Transaction tx = null;
        boolean salvou = false;
        try {
            tx = session.getTransaction();
            tx.begin();
            session.saveOrUpdate(obj);
            salvou = true;
            tx.commit();
        } catch (HibernateException e) {
            e.printStackTrace();
            session.getTransaction().rollback();
            salvou = false;
        }
        return salvou;
    }
        // </editor-fold>

    // <editor-fold defaultstate="collapsed" desc="DELETE"> 
    public static boolean excluir(int codigo, Class type) {
        Session session = HibernateUtil.openSession();
        Transaction tx = null;
        try {
            tx = session.getTransaction();
            tx.begin();
            Object object = session.get(type, codigo);
            session.delete(object);
            tx.commit();

        } catch (Exception e) {
            if (tx != null) {
                tx.rollback();
            }
            session.close();
            return false;
        } finally {
            session.close();
        }
        return true;
    }       
    // </editor-fold>

    // <editor-fold defaultstate="collapsed" desc="SEARCH OBJECT"> 
    public static Object buscarObjeto(int codigo, Class<?> classe) {
        Object objeto = null;
        Criteria criteria = getCriteria(classe);
        criteria.add(Restrictions.idEq(codigo));
        return getObject(criteria);
    }

    public static Object buscarObjeto(String codigo, Class<?> classe) {
        Object objeto = null;
        Criteria criteria = getCriteria(classe);
        criteria.add(Restrictions.idEq(codigo));
        return getObject(criteria);
    }

    public static Object buscarObjeto(HashMap<String, Object> filtros, Class<?> classe) {
        Object objeto = null;
        Criteria criteria = getCriteria(classe);
        for (Map.Entry<String, Object> entry : filtros.entrySet()) {
            String campo = entry.getKey();
            Object valor = entry.getValue();
            criteria.add(Restrictions.eq(campo, valor));
        }
        criteria.setMaxResults(1);//no maximo 1 resultado
        return getObject(criteria);
    }
        // </editor-fold>
      
    // <editor-fold defaultstate="collapsed" desc="SEARCH OBJECTS"> 
    public static Object buscarObjetos(HashMap<String, Object> filtros, Class<?> classe) {
        Object objeto = null;
        Criteria criteria = getCriteria(classe);
        for (Map.Entry<String, Object> entry : filtros.entrySet()) {
            String campo = entry.getKey();
            Object valor = entry.getValue();
            criteria.add(Restrictions.eq(campo, valor));
        }
        return getObjects(criteria);
    }

    public static ArrayList<?> buscarObjetos(Class<?> classe) {
        Object objeto = null;
        Criteria criteria = getCriteria(classe);
        return getObjects(criteria);
    }
        // </editor-fold>
    
    private static Object getObject(Criteria criteria) {
        return criteria.uniqueResult();
    }

    private static ArrayList<?> getObjects(Criteria criteria) {
        return (ArrayList<?>) criteria.list();
    }

    private static Criteria getCriteria(Class<?> classe) {
        Object objeto = null;
        Session session = HibernateUtil.openSession();
        Transaction tx = null;
        Criteria criteria = null;
        try {
            tx = session.getTransaction();//cria uma transação para o hibernate conectar no banco
            criteria = session.createCriteria(classe);
        } catch (Exception e) {
            if (tx != null) {
                tx.rollback();
            }
            e.printStackTrace();
        }
        return criteria;
    }
}
