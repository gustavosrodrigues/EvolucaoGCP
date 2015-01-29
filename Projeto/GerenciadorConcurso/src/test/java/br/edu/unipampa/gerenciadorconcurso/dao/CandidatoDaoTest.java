/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Candidato;
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
public class CandidatoDaoTest {
    
    public CandidatoDaoTest() {
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
     * Test of salvar method, of class CandidatoDao.
     */
    @Test
    public void testSalvar() {
        System.out.println("salvar");
        Candidato candidato = new Candidato();
        CandidatoDao instance = new CandidatoDao();
        DAO dao = new DAO();
        boolean expResult = dao.salvar(candidato);
        boolean result = instance.salvar(candidato);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class CandidatoDao.
     */
    @Test
    public void testBuscar_0args() {
        System.out.println("buscar");
        CandidatoDao instance = new CandidatoDao();
        ArrayList<Candidato> expResult = null;
        ArrayList<Candidato> result = instance.buscar();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class CandidatoDao.
     */
    @Test
    public void testBuscar_Concurso() {
        System.out.println("buscar");
        Concurso concurso = null;
        CandidatoDao instance = new CandidatoDao();
        ArrayList<Candidato> expResult = null;
        ArrayList<Candidato> result = instance.buscar(concurso);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class CandidatoDao.
     */
    @Test
    public void testBuscar_int() {
        System.out.println("buscar");
        int codigo = 0;
        CandidatoDao instance = new CandidatoDao();
        Candidato expResult = null;
        Candidato result = instance.buscar(codigo);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of deletar method, of class CandidatoDao.
     */
    @Test
    public void testDeletar() {
        System.out.println("deletar");
        int codigo = 0;
        CandidatoDao instance = new CandidatoDao();
        DAO dao = new DAO();
        boolean expResult = dao.excluir(codigo, Candidato.class);
        boolean result = instance.deletar(codigo);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
