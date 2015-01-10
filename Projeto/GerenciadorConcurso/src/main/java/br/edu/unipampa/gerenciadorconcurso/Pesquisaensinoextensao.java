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
@Table(name = "pesquisaensinoextensao")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Pesquisaensinoextensao.findAll", query = "SELECT p FROM Pesquisaensinoextensao p"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByMagisterioSuperior", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.magisterioSuperior = :magisterioSuperior"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByMagisterioEnsinoMedio", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.magisterioEnsinoMedio = :magisterioEnsinoMedio"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByAtividadeProfissional", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.atividadeProfissional = :atividadeProfissional"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByOrientacaoDoutorado", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.orientacaoDoutorado = :orientacaoDoutorado"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByOrientacaoMestrado", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.orientacaoMestrado = :orientacaoMestrado"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByOrientacaoMonografia", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.orientacaoMonografia = :orientacaoMonografia"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByOrientacaoIniciacaoCientifica", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.orientacaoIniciacaoCientifica = :orientacaoIniciacaoCientifica"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByMembroBancaDocentes", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.membroBancaDocentes = :membroBancaDocentes"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByMembroBancaProfessorSubstituto", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.membroBancaProfessorSubstituto = :membroBancaProfessorSubstituto"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByMembroBancaDoutorado", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.membroBancaDoutorado = :membroBancaDoutorado"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByMembroBancaMestrado", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.membroBancaMestrado = :membroBancaMestrado"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByMembroBancaMonografia", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.membroBancaMonografia = :membroBancaMonografia"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByCursoExtensao40hMais", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.cursoExtensao40hMais = :cursoExtensao40hMais"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByCursoExtensao20h40h", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.cursoExtensao20h40h = :cursoExtensao20h40h"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByPalestranteEventoInternacionaNacional", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.palestranteEventoInternacionaNacional = :palestranteEventoInternacionaNacional"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByPalestranteEventoLocalRegional", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.palestranteEventoLocalRegional = :palestranteEventoLocalRegional"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByCoodenadorProjetoPesquisa", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.coodenadorProjetoPesquisa = :coodenadorProjetoPesquisa"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByCooredenadorProjetoExtensao", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.cooredenadorProjetoExtensao = :cooredenadorProjetoExtensao"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByCoordenadorCursoGraduacao", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.coordenadorCursoGraduacao = :coordenadorCursoGraduacao"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByCoordenadorCursoEspecializacao", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.coordenadorCursoEspecializacao = :coordenadorCursoEspecializacao"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByDiretorUnidadeUniversitaria", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.diretorUnidadeUniversitaria = :diretorUnidadeUniversitaria"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByTitulo", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.titulo = :titulo"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByViciReitorProReitor", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.viciReitorProReitor = :viciReitorProReitor"),
    @NamedQuery(name = "Pesquisaensinoextensao.findByReitor", query = "SELECT p FROM Pesquisaensinoextensao p WHERE p.reitor = :reitor")})
public class Pesquisaensinoextensao implements Serializable {
    private static final long serialVersionUID = 1L;
    // @Max(value=?)  @Min(value=?)//if you know range of your decimal fields consider using these annotations to enforce field validation
    @Column(name = "magisterioSuperior")
    private Float magisterioSuperior;
    @Column(name = "magisterioEnsinoMedio")
    private Float magisterioEnsinoMedio;
    @Column(name = "atividadeProfissional")
    private Float atividadeProfissional;
    @Column(name = "orientacaoDoutorado")
    private Float orientacaoDoutorado;
    @Column(name = "orientacaoMestrado")
    private Float orientacaoMestrado;
    @Column(name = "orientacaoMonografia")
    private Float orientacaoMonografia;
    @Column(name = "orientacaoIniciacaoCientifica")
    private Float orientacaoIniciacaoCientifica;
    @Column(name = "membroBancaDocentes")
    private Float membroBancaDocentes;
    @Column(name = "membroBancaProfessorSubstituto")
    private Float membroBancaProfessorSubstituto;
    @Column(name = "membroBancaDoutorado")
    private Float membroBancaDoutorado;
    @Column(name = "membroBancaMestrado")
    private Float membroBancaMestrado;
    @Column(name = "MembroBancaMonografia")
    private Float membroBancaMonografia;
    @Column(name = "cursoExtensao40hMais")
    private Float cursoExtensao40hMais;
    @Column(name = "CursoExtensao20h40h")
    private Float cursoExtensao20h40h;
    @Column(name = "palestranteEventoInternacionaNacional")
    private Float palestranteEventoInternacionaNacional;
    @Column(name = "palestranteEventoLocalRegional")
    private Float palestranteEventoLocalRegional;
    @Column(name = "coodenadorProjetoPesquisa")
    private Float coodenadorProjetoPesquisa;
    @Column(name = "cooredenadorProjetoExtensao")
    private Float cooredenadorProjetoExtensao;
    @Column(name = "coordenadorCursoGraduacao")
    private Float coordenadorCursoGraduacao;
    @Column(name = "coordenadorCursoEspecializacao")
    private Float coordenadorCursoEspecializacao;
    @Column(name = "diretorUnidadeUniversitaria")
    private Float diretorUnidadeUniversitaria;
    @Id
    @Basic(optional = false)
    @Column(name = "titulo")
    private Integer titulo;
    @Column(name = "viciReitorProReitor")
    private Float viciReitorProReitor;
    @Column(name = "reitor")
    private Float reitor;
    @JoinColumn(name = "titulo", referencedColumnName = "codigo", insertable = false, updatable = false)
    @OneToOne(optional = false)
    private Titulo titulo1;

    public Pesquisaensinoextensao() {
    }

    public Pesquisaensinoextensao(Integer titulo) {
        this.titulo = titulo;
    }

    public Float getMagisterioSuperior() {
        return magisterioSuperior;
    }

    public void setMagisterioSuperior(Float magisterioSuperior) {
        this.magisterioSuperior = magisterioSuperior;
    }

    public Float getMagisterioEnsinoMedio() {
        return magisterioEnsinoMedio;
    }

    public void setMagisterioEnsinoMedio(Float magisterioEnsinoMedio) {
        this.magisterioEnsinoMedio = magisterioEnsinoMedio;
    }

    public Float getAtividadeProfissional() {
        return atividadeProfissional;
    }

    public void setAtividadeProfissional(Float atividadeProfissional) {
        this.atividadeProfissional = atividadeProfissional;
    }

    public Float getOrientacaoDoutorado() {
        return orientacaoDoutorado;
    }

    public void setOrientacaoDoutorado(Float orientacaoDoutorado) {
        this.orientacaoDoutorado = orientacaoDoutorado;
    }

    public Float getOrientacaoMestrado() {
        return orientacaoMestrado;
    }

    public void setOrientacaoMestrado(Float orientacaoMestrado) {
        this.orientacaoMestrado = orientacaoMestrado;
    }

    public Float getOrientacaoMonografia() {
        return orientacaoMonografia;
    }

    public void setOrientacaoMonografia(Float orientacaoMonografia) {
        this.orientacaoMonografia = orientacaoMonografia;
    }

    public Float getOrientacaoIniciacaoCientifica() {
        return orientacaoIniciacaoCientifica;
    }

    public void setOrientacaoIniciacaoCientifica(Float orientacaoIniciacaoCientifica) {
        this.orientacaoIniciacaoCientifica = orientacaoIniciacaoCientifica;
    }

    public Float getMembroBancaDocentes() {
        return membroBancaDocentes;
    }

    public void setMembroBancaDocentes(Float membroBancaDocentes) {
        this.membroBancaDocentes = membroBancaDocentes;
    }

    public Float getMembroBancaProfessorSubstituto() {
        return membroBancaProfessorSubstituto;
    }

    public void setMembroBancaProfessorSubstituto(Float membroBancaProfessorSubstituto) {
        this.membroBancaProfessorSubstituto = membroBancaProfessorSubstituto;
    }

    public Float getMembroBancaDoutorado() {
        return membroBancaDoutorado;
    }

    public void setMembroBancaDoutorado(Float membroBancaDoutorado) {
        this.membroBancaDoutorado = membroBancaDoutorado;
    }

    public Float getMembroBancaMestrado() {
        return membroBancaMestrado;
    }

    public void setMembroBancaMestrado(Float membroBancaMestrado) {
        this.membroBancaMestrado = membroBancaMestrado;
    }

    public Float getMembroBancaMonografia() {
        return membroBancaMonografia;
    }

    public void setMembroBancaMonografia(Float membroBancaMonografia) {
        this.membroBancaMonografia = membroBancaMonografia;
    }

    public Float getCursoExtensao40hMais() {
        return cursoExtensao40hMais;
    }

    public void setCursoExtensao40hMais(Float cursoExtensao40hMais) {
        this.cursoExtensao40hMais = cursoExtensao40hMais;
    }

    public Float getCursoExtensao20h40h() {
        return cursoExtensao20h40h;
    }

    public void setCursoExtensao20h40h(Float cursoExtensao20h40h) {
        this.cursoExtensao20h40h = cursoExtensao20h40h;
    }

    public Float getPalestranteEventoInternacionaNacional() {
        return palestranteEventoInternacionaNacional;
    }

    public void setPalestranteEventoInternacionaNacional(Float palestranteEventoInternacionaNacional) {
        this.palestranteEventoInternacionaNacional = palestranteEventoInternacionaNacional;
    }

    public Float getPalestranteEventoLocalRegional() {
        return palestranteEventoLocalRegional;
    }

    public void setPalestranteEventoLocalRegional(Float palestranteEventoLocalRegional) {
        this.palestranteEventoLocalRegional = palestranteEventoLocalRegional;
    }

    public Float getCoodenadorProjetoPesquisa() {
        return coodenadorProjetoPesquisa;
    }

    public void setCoodenadorProjetoPesquisa(Float coodenadorProjetoPesquisa) {
        this.coodenadorProjetoPesquisa = coodenadorProjetoPesquisa;
    }

    public Float getCooredenadorProjetoExtensao() {
        return cooredenadorProjetoExtensao;
    }

    public void setCooredenadorProjetoExtensao(Float cooredenadorProjetoExtensao) {
        this.cooredenadorProjetoExtensao = cooredenadorProjetoExtensao;
    }

    public Float getCoordenadorCursoGraduacao() {
        return coordenadorCursoGraduacao;
    }

    public void setCoordenadorCursoGraduacao(Float coordenadorCursoGraduacao) {
        this.coordenadorCursoGraduacao = coordenadorCursoGraduacao;
    }

    public Float getCoordenadorCursoEspecializacao() {
        return coordenadorCursoEspecializacao;
    }

    public void setCoordenadorCursoEspecializacao(Float coordenadorCursoEspecializacao) {
        this.coordenadorCursoEspecializacao = coordenadorCursoEspecializacao;
    }

    public Float getDiretorUnidadeUniversitaria() {
        return diretorUnidadeUniversitaria;
    }

    public void setDiretorUnidadeUniversitaria(Float diretorUnidadeUniversitaria) {
        this.diretorUnidadeUniversitaria = diretorUnidadeUniversitaria;
    }

    public Integer getTitulo() {
        return titulo;
    }

    public void setTitulo(Integer titulo) {
        this.titulo = titulo;
    }

    public Float getViciReitorProReitor() {
        return viciReitorProReitor;
    }

    public void setViciReitorProReitor(Float viciReitorProReitor) {
        this.viciReitorProReitor = viciReitorProReitor;
    }

    public Float getReitor() {
        return reitor;
    }

    public void setReitor(Float reitor) {
        this.reitor = reitor;
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
        if (!(object instanceof Pesquisaensinoextensao)) {
            return false;
        }
        Pesquisaensinoextensao other = (Pesquisaensinoextensao) object;
        if ((this.titulo == null && other.titulo != null) || (this.titulo != null && !this.titulo.equals(other.titulo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Pesquisaensinoextensao[ titulo=" + titulo + " ]";
    }
    
}
