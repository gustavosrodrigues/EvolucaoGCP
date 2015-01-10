/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso;

import java.io.Serializable;
import javax.persistence.Basic;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.OneToOne;
import javax.persistence.Table;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Douglas
 */
@Entity
@Table(name = "producaoartistica")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Producaoartistica.findAll", query = "SELECT p FROM Producaoartistica p"),
    @NamedQuery(name = "Producaoartistica.findByAuditoriaIndividualLivroInternacional", query = "SELECT p FROM Producaoartistica p WHERE p.auditoriaIndividualLivroInternacional = :auditoriaIndividualLivroInternacional"),
    @NamedQuery(name = "Producaoartistica.findByAuditoriaIndividualLivroNacional", query = "SELECT p FROM Producaoartistica p WHERE p.auditoriaIndividualLivroNacional = :auditoriaIndividualLivroNacional"),
    @NamedQuery(name = "Producaoartistica.findByCoAutoriaLivro", query = "SELECT p FROM Producaoartistica p WHERE p.coAutoriaLivro = :coAutoriaLivro"),
    @NamedQuery(name = "Producaoartistica.findByAditoriaCapituloLivro", query = "SELECT p FROM Producaoartistica p WHERE p.aditoriaCapituloLivro = :aditoriaCapituloLivro"),
    @NamedQuery(name = "Producaoartistica.findByArtigoA1A2", query = "SELECT p FROM Producaoartistica p WHERE p.artigoA1A2 = :artigoA1A2"),
    @NamedQuery(name = "Producaoartistica.findByArtigoB1B2", query = "SELECT p FROM Producaoartistica p WHERE p.artigoB1B2 = :artigoB1B2"),
    @NamedQuery(name = "Producaoartistica.findByArtigoB3B4", query = "SELECT p FROM Producaoartistica p WHERE p.artigoB3B4 = :artigoB3B4"),
    @NamedQuery(name = "Producaoartistica.findByArtigoB5", query = "SELECT p FROM Producaoartistica p WHERE p.artigoB5 = :artigoB5"),
    @NamedQuery(name = "Producaoartistica.findByArtigoNaoClassificado", query = "SELECT p FROM Producaoartistica p WHERE p.artigoNaoClassificado = :artigoNaoClassificado"),
    @NamedQuery(name = "Producaoartistica.findByTrabalhoA1A2", query = "SELECT p FROM Producaoartistica p WHERE p.trabalhoA1A2 = :trabalhoA1A2"),
    @NamedQuery(name = "Producaoartistica.findByTrabalhoB1B2B3", query = "SELECT p FROM Producaoartistica p WHERE p.trabalhoB1B2B3 = :trabalhoB1B2B3"),
    @NamedQuery(name = "Producaoartistica.findByTrabalhoB4B5", query = "SELECT p FROM Producaoartistica p WHERE p.trabalhoB4B5 = :trabalhoB4B5"),
    @NamedQuery(name = "Producaoartistica.findByTrabalhoNaoClassificado", query = "SELECT p FROM Producaoartistica p WHERE p.trabalhoNaoClassificado = :trabalhoNaoClassificado"),
    @NamedQuery(name = "Producaoartistica.findByPatenteOuLice\u00e7a", query = "SELECT p FROM Producaoartistica p WHERE p.patenteOuLice\u00e7a = :patenteOuLice\u00e7a"),
    @NamedQuery(name = "Producaoartistica.findByPremiosTitulosInternacional", query = "SELECT p FROM Producaoartistica p WHERE p.premiosTitulosInternacional = :premiosTitulosInternacional"),
    @NamedQuery(name = "Producaoartistica.findByPremiosTitulosNacional", query = "SELECT p FROM Producaoartistica p WHERE p.premiosTitulosNacional = :premiosTitulosNacional"),
    @NamedQuery(name = "Producaoartistica.findByPremiosTitulosRegional", query = "SELECT p FROM Producaoartistica p WHERE p.premiosTitulosRegional = :premiosTitulosRegional"),
    @NamedQuery(name = "Producaoartistica.findByPromocaoProducaoLocal", query = "SELECT p FROM Producaoartistica p WHERE p.promocaoProducaoLocal = :promocaoProducaoLocal"),
    @NamedQuery(name = "Producaoartistica.findByPromocaoProducaoNacional", query = "SELECT p FROM Producaoartistica p WHERE p.promocaoProducaoNacional = :promocaoProducaoNacional"),
    @NamedQuery(name = "Producaoartistica.findByPromocaoProducaoInternacional", query = "SELECT p FROM Producaoartistica p WHERE p.promocaoProducaoInternacional = :promocaoProducaoInternacional"),
    @NamedQuery(name = "Producaoartistica.findByFilmesVideosDiscos", query = "SELECT p FROM Producaoartistica p WHERE p.filmesVideosDiscos = :filmesVideosDiscos"),
    @NamedQuery(name = "Producaoartistica.findByTitulo", query = "SELECT p FROM Producaoartistica p WHERE p.titulo = :titulo")})
public class Producaoartistica implements Serializable {
    private static final long serialVersionUID = 1L;
    // @Max(value=?)  @Min(value=?)//if you know range of your decimal fields consider using these annotations to enforce field validation
    @Column(name = "auditoriaIndividualLivroInternacional")
    private Float auditoriaIndividualLivroInternacional;
    @Column(name = "auditoriaIndividualLivroNacional")
    private Float auditoriaIndividualLivroNacional;
    @Column(name = "coAutoriaLivro")
    private Float coAutoriaLivro;
    @Column(name = "aditoriaCapituloLivro")
    private Float aditoriaCapituloLivro;
    @Column(name = "artigoA1A2")
    private Float artigoA1A2;
    @Column(name = "artigoB1B2")
    private Float artigoB1B2;
    @Column(name = "artigoB3B4")
    private Float artigoB3B4;
    @Column(name = "artigoB5")
    private Float artigoB5;
    @Column(name = "artigoNaoClassificado")
    private Float artigoNaoClassificado;
    @Column(name = "trabalhoA1A2")
    private Float trabalhoA1A2;
    @Column(name = "trabalhoB1B2B3")
    private Float trabalhoB1B2B3;
    @Column(name = "trabalhoB4B5")
    private Float trabalhoB4B5;
    @Column(name = "trabalhoNaoClassificado")
    private Float trabalhoNaoClassificado;
    @Column(name = "patenteOuLice\u00e7a")
    private Float patenteOuLiceça;
    @Column(name = "premiosTitulosInternacional")
    private Float premiosTitulosInternacional;
    @Column(name = "premiosTitulosNacional")
    private Float premiosTitulosNacional;
    @Column(name = "premiosTitulosRegional")
    private Float premiosTitulosRegional;
    @Column(name = "promocaoProducaoLocal")
    private Float promocaoProducaoLocal;
    @Column(name = "promocaoProducaoNacional")
    private Float promocaoProducaoNacional;
    @Column(name = "promocaoProducaoInternacional")
    private Float promocaoProducaoInternacional;
    @Column(name = "FilmesVideosDiscos")
    private Float filmesVideosDiscos;
    @Id
    @Basic(optional = false)
    @Column(name = "titulo")
    private Integer titulo;
    @JoinColumn(name = "titulo", referencedColumnName = "codigo", insertable = false, updatable = false)
    @OneToOne(optional = false)
    private Titulo titulo1;

    public Producaoartistica() {
    }

    public Producaoartistica(Integer titulo) {
        this.titulo = titulo;
    }

    public Float getAuditoriaIndividualLivroInternacional() {
        return auditoriaIndividualLivroInternacional;
    }

    public void setAuditoriaIndividualLivroInternacional(Float auditoriaIndividualLivroInternacional) {
        this.auditoriaIndividualLivroInternacional = auditoriaIndividualLivroInternacional;
    }

    public Float getAuditoriaIndividualLivroNacional() {
        return auditoriaIndividualLivroNacional;
    }

    public void setAuditoriaIndividualLivroNacional(Float auditoriaIndividualLivroNacional) {
        this.auditoriaIndividualLivroNacional = auditoriaIndividualLivroNacional;
    }

    public Float getCoAutoriaLivro() {
        return coAutoriaLivro;
    }

    public void setCoAutoriaLivro(Float coAutoriaLivro) {
        this.coAutoriaLivro = coAutoriaLivro;
    }

    public Float getAditoriaCapituloLivro() {
        return aditoriaCapituloLivro;
    }

    public void setAditoriaCapituloLivro(Float aditoriaCapituloLivro) {
        this.aditoriaCapituloLivro = aditoriaCapituloLivro;
    }

    public Float getArtigoA1A2() {
        return artigoA1A2;
    }

    public void setArtigoA1A2(Float artigoA1A2) {
        this.artigoA1A2 = artigoA1A2;
    }

    public Float getArtigoB1B2() {
        return artigoB1B2;
    }

    public void setArtigoB1B2(Float artigoB1B2) {
        this.artigoB1B2 = artigoB1B2;
    }

    public Float getArtigoB3B4() {
        return artigoB3B4;
    }

    public void setArtigoB3B4(Float artigoB3B4) {
        this.artigoB3B4 = artigoB3B4;
    }

    public Float getArtigoB5() {
        return artigoB5;
    }

    public void setArtigoB5(Float artigoB5) {
        this.artigoB5 = artigoB5;
    }

    public Float getArtigoNaoClassificado() {
        return artigoNaoClassificado;
    }

    public void setArtigoNaoClassificado(Float artigoNaoClassificado) {
        this.artigoNaoClassificado = artigoNaoClassificado;
    }

    public Float getTrabalhoA1A2() {
        return trabalhoA1A2;
    }

    public void setTrabalhoA1A2(Float trabalhoA1A2) {
        this.trabalhoA1A2 = trabalhoA1A2;
    }

    public Float getTrabalhoB1B2B3() {
        return trabalhoB1B2B3;
    }

    public void setTrabalhoB1B2B3(Float trabalhoB1B2B3) {
        this.trabalhoB1B2B3 = trabalhoB1B2B3;
    }

    public Float getTrabalhoB4B5() {
        return trabalhoB4B5;
    }

    public void setTrabalhoB4B5(Float trabalhoB4B5) {
        this.trabalhoB4B5 = trabalhoB4B5;
    }

    public Float getTrabalhoNaoClassificado() {
        return trabalhoNaoClassificado;
    }

    public void setTrabalhoNaoClassificado(Float trabalhoNaoClassificado) {
        this.trabalhoNaoClassificado = trabalhoNaoClassificado;
    }

    public Float getPatenteOuLiceça() {
        return patenteOuLiceça;
    }

    public void setPatenteOuLiceça(Float patenteOuLiceça) {
        this.patenteOuLiceça = patenteOuLiceça;
    }

    public Float getPremiosTitulosInternacional() {
        return premiosTitulosInternacional;
    }

    public void setPremiosTitulosInternacional(Float premiosTitulosInternacional) {
        this.premiosTitulosInternacional = premiosTitulosInternacional;
    }

    public Float getPremiosTitulosNacional() {
        return premiosTitulosNacional;
    }

    public void setPremiosTitulosNacional(Float premiosTitulosNacional) {
        this.premiosTitulosNacional = premiosTitulosNacional;
    }

    public Float getPremiosTitulosRegional() {
        return premiosTitulosRegional;
    }

    public void setPremiosTitulosRegional(Float premiosTitulosRegional) {
        this.premiosTitulosRegional = premiosTitulosRegional;
    }

    public Float getPromocaoProducaoLocal() {
        return promocaoProducaoLocal;
    }

    public void setPromocaoProducaoLocal(Float promocaoProducaoLocal) {
        this.promocaoProducaoLocal = promocaoProducaoLocal;
    }

    public Float getPromocaoProducaoNacional() {
        return promocaoProducaoNacional;
    }

    public void setPromocaoProducaoNacional(Float promocaoProducaoNacional) {
        this.promocaoProducaoNacional = promocaoProducaoNacional;
    }

    public Float getPromocaoProducaoInternacional() {
        return promocaoProducaoInternacional;
    }

    public void setPromocaoProducaoInternacional(Float promocaoProducaoInternacional) {
        this.promocaoProducaoInternacional = promocaoProducaoInternacional;
    }

    public Float getFilmesVideosDiscos() {
        return filmesVideosDiscos;
    }

    public void setFilmesVideosDiscos(Float filmesVideosDiscos) {
        this.filmesVideosDiscos = filmesVideosDiscos;
    }

    public Integer getTitulo() {
        return titulo;
    }

    public void setTitulo(Integer titulo) {
        this.titulo = titulo;
    }

    public Titulo getTitulo1() {
        return titulo1;
    }

    public void setTitulo1(Titulo titulo1) {
        this.titulo1 = titulo1;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (titulo != null ? titulo.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Producaoartistica)) {
            return false;
        }
        Producaoartistica other = (Producaoartistica) object;
        if ((this.titulo == null && other.titulo != null) || (this.titulo != null && !this.titulo.equals(other.titulo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Producaoartistica[ titulo=" + titulo + " ]";
    }
    
}
