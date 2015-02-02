/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Examinador;
import java.util.ArrayList;
import java.util.HashMap;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Gustavo Rodrigues
 */
public class ExaminadorDaoTest {
    
    public ExaminadorDaoTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of salvar method, of class ExaminadorDao.
     */
    @Test
    public void testSalvar() {
        System.out.println("salvar");
        Examinador examinador = new Examinador();
        ExaminadorDao instance = new ExaminadorDao();
        DAO dao = new DAO();
        boolean expResult = dao.salvar(examinador);;
        boolean result = instance.salvar(examinador);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class ExaminadorDao.
     */
    @Test
    public void testBuscar_0args() {
        System.out.println("buscar");
        ExaminadorDao instance = new ExaminadorDao();
        DAO dao = new DAO();
        ArrayList<Examinador> expResult = (ArrayList<Examinador>) dao.buscarObjetos(Examinador.class);;
        ArrayList<Examinador> result = instance.buscar();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class ExaminadorDao.
     */
    @Test
    public void testBuscar_Concurso() {
        System.out.println("buscar");
        Concurso concurso = new Concurso();
        ExaminadorDao instance = new ExaminadorDao();
        DAO dao = new DAO();
        HashMap<String, Object> filtros = new HashMap<>();
        filtros.put("concurso.codigo", concurso.getCodigo());        
        ArrayList<Examinador> expResult = (ArrayList<Examinador>) dao.buscarObjetos(filtros,Examinador.class);;
        ArrayList<Examinador> result = instance.buscar(concurso);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class ExaminadorDao.
     */
    @Test
    public void testBuscar_int() {
        System.out.println("buscar");
        int codigo = 1;
        ExaminadorDao instance = new ExaminadorDao();
        DAO dao = new DAO();
        Examinador expResult = (Examinador) dao.buscarObjeto(codigo, Examinador.class);;
        Examinador result = instance.buscar(codigo);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of deletar method, of class ExaminadorDao.
     */
    @Test
    public void testDeletar() {
        System.out.println("deletar");
        int codigo = 1;
        ExaminadorDao instance = new ExaminadorDao();
        DAO dao = new DAO();
        boolean expResult = dao.excluir(codigo, Examinador.class);;
        boolean result = instance.deletar(codigo);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}