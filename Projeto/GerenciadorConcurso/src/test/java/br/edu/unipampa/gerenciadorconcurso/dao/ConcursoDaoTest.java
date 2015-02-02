/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import java.util.ArrayList;
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
public class ConcursoDaoTest {
    
    public ConcursoDaoTest() {
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
     * Test of salvar method, of class ConcursoDao.
     */
    @Test
    public void testSalvar() {
        System.out.println("salvar");
        Concurso concurso = new Concurso();
        ConcursoDao instance = new ConcursoDao();
        DAO dao = new DAO();
        boolean expResult = dao.salvar(concurso);
        boolean result = instance.salvar(concurso);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class ConcursoDao.
     */
    @Test
    public void testBuscar_0args() {
        System.out.println("buscar");
        ConcursoDao instance = new ConcursoDao();
        DAO dao = new DAO();
        ArrayList<Concurso> expResult = (ArrayList<Concurso>) dao.buscarObjetos(Concurso.class);
        ArrayList<Concurso> result = instance.buscar();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class ConcursoDao.
     */
    @Test
    public void testBuscar_int() {
        System.out.println("buscar");
        int codigo = 1;
        ConcursoDao instance = new ConcursoDao();
        DAO dao = new DAO();
        Concurso expResult = (Concurso) dao.buscarObjeto(codigo, Concurso.class);
        Concurso result = instance.buscar(codigo);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of deletar method, of class ConcursoDao.
     */
    @Test
    public void testDeletar() {
        System.out.println("deletar");
        int codigo = 1;
        ConcursoDao instance = new ConcursoDao();
        DAO dao = new DAO();
        boolean expResult = dao.excluir(codigo, Concurso.class);
        boolean result = instance.deletar(codigo);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
