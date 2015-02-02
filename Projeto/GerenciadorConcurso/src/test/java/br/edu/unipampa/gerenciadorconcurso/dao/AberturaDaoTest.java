/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Abertura;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Candidato;
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
public class AberturaDaoTest {
    
    public AberturaDaoTest() {
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
     * Test of salvar method, of class AberturaDao.
     */
    @Test
    public void testSalvar() {
        System.out.println("salvar");
        Abertura abertura = new Abertura();
        AberturaDao instance = new AberturaDao();
        DAO dao = new DAO();
        boolean expResult = dao.salvar(abertura);
        boolean result = instance.salvar(abertura);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //  fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class AberturaDao.
     */
    @Test
    public void testBuscar_0args() {
        System.out.println("buscar");
        AberturaDao instance = new AberturaDao();
        DAO dao = new DAO();      
        ArrayList<Abertura> expResult = (ArrayList<Abertura>) dao.buscarObjetos(Candidato.class);
        ArrayList<Abertura> result = instance.buscar();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        // fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class AberturaDao.
     */
    @Test
    public void testBuscar_Concurso() {
        System.out.println("buscar");
        Concurso concurso = new Concurso();
        AberturaDao instance = new AberturaDao();
        DAO dao = new DAO();
        HashMap<String, Object> filtros = new HashMap<>();
        filtros.put("concurso.codigo", concurso.getCodigo());
        ArrayList<Abertura> expResult = (ArrayList<Abertura>) dao.buscarObjetos(filtros,Abertura.class);
        ArrayList<Abertura> result = instance.buscar(concurso);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class AberturaDao.
     */
    @Test
    public void testBuscar_int() {
        System.out.println("buscar");
        int codigo = 0;
        AberturaDao instance = new AberturaDao();
        DAO dao = new DAO();
        Abertura expResult = (Abertura) dao.buscarObjeto(codigo, Abertura.class);
        Abertura result = instance.buscar(codigo);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscarAberturaPorConcurso method, of class AberturaDao.
     */
    @Test
    public void testBuscarAberturaPorConcurso() {
        System.out.println("buscarAberturaPorConcurso");
        Concurso concurso = new Concurso();
        AberturaDao abertura = new AberturaDao();        
        Abertura ab = new Abertura();
        DAO dao = new DAO();
        Abertura expResult = ab;
        Abertura result = abertura.buscarAberturaPorConcurso(concurso);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of deletar method, of class AberturaDao.
     */
    @Test
    public void testDeletar() {
        System.out.println("deletar");
        int codigo = 0;
        AberturaDao instance = new AberturaDao();
        DAO dao = new DAO();
        boolean expResult = dao.excluir(codigo, Abertura.class);
        boolean result = instance.deletar(codigo);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
//    
//}
//
//    /**
//     * Test of buscar method, of class AberturaDao.
//     */
//    @Test
//    public void testBuscar_0args() {
//        System.out.println("buscar");
//        AberturaDao instance = new AberturaDao();
//        ArrayList<Abertura> expResult = null;
//        ArrayList<Abertura> result = instance.buscar();
//        assertEquals(expResult, result);
//        // TODO review the generated test code and remove the default call to fail.
//        fail("The test case is a prototype.");
//    }
//
//    /**
//     * Test of buscar method, of class AberturaDao.
//     */
//    @Test
//    public void testBuscar_Concurso() {
//        System.out.println("buscar");
//        Concurso concurso = null;
//        AberturaDao instance = new AberturaDao();
//        ArrayList<Abertura> expResult = null;
//        ArrayList<Abertura> result = instance.buscar(concurso);
//        assertEquals(expResult, result);
//        // TODO review the generated test code and remove the default call to fail.
//        fail("The test case is a prototype.");
//    }
//
//    /**
//     * Test of buscar method, of class AberturaDao.
//     */
//    @Test
//    public void testBuscar_int() {
//        System.out.println("buscar");
//        int codigo = 0;
//        AberturaDao instance = new AberturaDao();
//        Abertura expResult = null;
//        Abertura result = instance.buscar(codigo);
//        assertEquals(expResult, result);
//        // TODO review the generated test code and remove the default call to fail.
//        fail("The test case is a prototype.");
//    }
//
//    /**
//     * Test of buscarAberturaPorConcurso method, of class AberturaDao.
//     */
//    @Test
//    public void testBuscarAberturaPorConcurso() {
//        System.out.println("buscarAberturaPorConcurso");
//        Concurso concurso = null;
//        AberturaDao instance = new AberturaDao();
//        Abertura expResult = null;
//        Abertura result = instance.buscarAberturaPorConcurso(concurso);
//        assertEquals(expResult, result);
//        // TODO review the generated test code and remove the default call to fail.
//        fail("The test case is a prototype.");
//    }
//
//    /**
//     * Test of deletar method, of class AberturaDao.
//     */
//    @Test
//    public void testDeletar() {
//        System.out.println("deletar");
//        int codigo = 0;
//        AberturaDao instance = new AberturaDao();
//        boolean expResult = false;
//        boolean result = instance.deletar(codigo);
//        assertEquals(expResult, result);
//        // TODO review the generated test code and remove the default call to fail.
//        fail("The test case is a prototype.");
//    }
//    
//}
//
//    /**
//     * Test of buscar method, of class AberturaDao.
//     */
//    @Test
//    public void testBuscar_0args() {
//        System.out.println("buscar");
//        AberturaDao instance = new AberturaDao();
//        ArrayList<Abertura> expResult = null;
//        ArrayList<Abertura> result = instance.buscar();
//        assertEquals(expResult, result);
//        // TODO review the generated test code and remove the default call to fail.
//        fail("The test case is a prototype.");
//    }
//
//    /**
//     * Test of buscar method, of class AberturaDao.
//     */
//    @Test
//    public void testBuscar_Concurso() {
//        System.out.println("buscar");
//        Concurso concurso = null;
//        AberturaDao instance = new AberturaDao();
//        ArrayList<Abertura> expResult = null;
//        ArrayList<Abertura> result = instance.buscar(concurso);
//        assertEquals(expResult, result);
//        // TODO review the generated test code and remove the default call to fail.
//        fail("The test case is a prototype.");
//    }
//
//    /**
//     * Test of buscar method, of class AberturaDao.
//     */
//    @Test
//    public void testBuscar_int() {
//        System.out.println("buscar");
//        int codigo = 0;
//        AberturaDao instance = new AberturaDao();
//        Abertura expResult = null;
//        Abertura result = instance.buscar(codigo);
//        assertEquals(expResult, result);
//        // TODO review the generated test code and remove the default call to fail.
//        fail("The test case is a prototype.");
//    }
//
//    /**
//     * Test of buscarAberturaPorConcurso method, of class AberturaDao.
//     */
//    @Test
//    public void testBuscarAberturaPorConcurso() {
//        System.out.println("buscarAberturaPorConcurso");
//        Concurso concurso = null;
//        AberturaDao instance = new AberturaDao();
//        Abertura expResult = null;
//        Abertura result = instance.buscarAberturaPorConcurso(concurso);
//        assertEquals(expResult, result);
//        // TODO review the generated test code and remove the default call to fail.
//        fail("The test case is a prototype.");
//    }
//
//    /**
//     * Test of deletar method, of class AberturaDao.
//     */
//    @Test
//    public void testDeletar() {
//        System.out.println("deletar");
//        int codigo = 0;
//        AberturaDao instance = new AberturaDao();
//        boolean expResult = false;
//        boolean result = instance.deletar(codigo);
//        assertEquals(expResult, result);
//        // TODO review the generated test code and remove the default call to fail.
//        fail("The test case is a prototype.");
//    }
    
}
