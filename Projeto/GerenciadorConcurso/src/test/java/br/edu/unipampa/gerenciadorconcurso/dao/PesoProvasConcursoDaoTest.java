/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Pesoprovas;
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
public class PesoProvasConcursoDaoTest {
    
    public PesoProvasConcursoDaoTest() {
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
     * Test of salvar method, of class PesoProvasConcursoDao.
     */
    @Test
    public void testSalvar() {
        System.out.println("salvar");
        Pesoprovas pesoprovas = new Pesoprovas();
        PesoProvasConcursoDao instance = new PesoProvasConcursoDao();
        DAO dao = new DAO();
        boolean expResult = dao.salvar(pesoprovas);
        boolean result = instance.salvar(pesoprovas);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class PesoProvasConcursoDao.
     */
    @Test
    public void testBuscar_0args() {
        System.out.println("buscar");
        PesoProvasConcursoDao instance = new PesoProvasConcursoDao();
        DAO dao = new DAO();
        ArrayList<Pesoprovas> expResult = (ArrayList<Pesoprovas>) dao.buscarObjetos(Pesoprovas.class);;        
        ArrayList<Pesoprovas> result = instance.buscar();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class PesoProvasConcursoDao.
     */
    @Test
    public void testBuscar_int() {
        System.out.println("buscar");
        int codigo = 0;
        PesoProvasConcursoDao instance = new PesoProvasConcursoDao();
        DAO dao = new DAO();
        Pesoprovas expResult = (Pesoprovas) dao.buscarObjeto(codigo, Pesoprovas.class);;
        Pesoprovas result = instance.buscar(codigo);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscarPesoProvasConcurso method, of class PesoProvasConcursoDao.
     */
    @Test
    public void testBuscarPesoProvasConcurso() {
        System.out.println("buscarPesoProvasConcurso");
        Concurso concurso = null;
        PesoProvasConcursoDao instance = new PesoProvasConcursoDao();
        DAO dao = new DAO();
        HashMap<String, Object> filtro = new HashMap<>();
        filtro.put("concurso.codigo", concurso.getCodigo());        
        Pesoprovas expResult = (Pesoprovas) dao.buscarObjeto(filtro, Pesoprovas.class);;
        Pesoprovas result = instance.buscarPesoProvasConcurso(concurso);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of deletar method, of class PesoProvasConcursoDao.
     */
    @Test
    public void testDeletar() {
        System.out.println("deletar");
        int codigo = 0;
        PesoProvasConcursoDao instance = new PesoProvasConcursoDao();
        DAO dao = new DAO();
        boolean expResult = dao.excluir(codigo, Pesoprovas.class);;
        boolean result = instance.deletar(codigo);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
