/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.dao;

import br.edu.unipampa.gerenciadorconcurso.model.Abertura;
import br.edu.unipampa.gerenciadorconcurso.model.Concurso;
import br.edu.unipampa.gerenciadorconcurso.model.Registrocronograma;
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
public class ConogramaDaoTest {
    
    public ConogramaDaoTest() {
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
     * Test of salvar method, of class ConogramaDao.
     */
    @Test
    public void testSalvar() {
        System.out.println("salvar");
        Registrocronograma conograma = new Registrocronograma();
        ConogramaDao instance = new ConogramaDao();
        DAO dao = new DAO();
        boolean expResult = dao.salvar(conograma);
        boolean result = instance.salvar(conograma);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscar method, of class ConogramaDao.
     */
    @Test
    public void testBuscar() {
        System.out.println("buscar");
        ConogramaDao instance = new ConogramaDao();
        DAO dao = new DAO();
        ArrayList<Registrocronograma> expResult = (ArrayList<Registrocronograma>) dao.buscarObjetos(Registrocronograma.class);;
        ArrayList<Registrocronograma> result = instance.buscar();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of buscarConogramaPorConcurso method, of class ConogramaDao.
     */
    @Test
    public void testBuscarConogramaPorConcurso() {
        System.out.println("buscarConogramaPorConcurso");
        Concurso concurso = new Concurso();
        ConogramaDao instance = new ConogramaDao();
        AberturaDao aberturaDao = new AberturaDao();
        Abertura abertura = new Abertura();
        ArrayList<Abertura> aberturas = aberturaDao.buscar(concurso);
        DAO dao = new DAO();        
        HashMap<String, Object> filtro = new HashMap<>();
        filtro.put("abertura.codigo", abertura.getCodigo());
        ArrayList<Registrocronograma> expResult = (ArrayList<Registrocronograma>) dao.buscarObjetos(filtro, Registrocronograma.class);
        ArrayList<Registrocronograma> result = instance.buscarConogramaPorConcurso(concurso);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of deletar method, of class ConogramaDao.
     */
    @Test
    public void testDeletar() {
        System.out.println("deletar");
        int codigo = 1;
        ConogramaDao instance = new ConogramaDao();
        DAO dao = new DAO();
        boolean expResult = dao.excluir(codigo, Registrocronograma.class);
        boolean result = instance.deletar(codigo);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
