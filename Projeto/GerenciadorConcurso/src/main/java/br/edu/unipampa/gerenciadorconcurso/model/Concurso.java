/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.model;

import java.io.Serializable;
import java.util.Collection;
import javax.persistence.Basic;
import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.OneToMany;
import javax.persistence.Table;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlTransient;

/**
 *
 * @author Douglas
 */
@Entity
@Table(name = "concurso")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Concurso.findAll", query = "SELECT c FROM Concurso c"),
    @NamedQuery(name = "Concurso.findByCodigo", query = "SELECT c FROM Concurso c WHERE c.codigo = :codigo"),
    @NamedQuery(name = "Concurso.findByEdital", query = "SELECT c FROM Concurso c WHERE c.edital = :edital"),
    @NamedQuery(name = "Concurso.findByArea", query = "SELECT c FROM Concurso c WHERE c.area = :area"),
    @NamedQuery(name = "Concurso.findByClasse", query = "SELECT c FROM Concurso c WHERE c.classe = :classe"),
    @NamedQuery(name = "Concurso.findByCampus", query = "SELECT c FROM Concurso c WHERE c.campus = :campus"),
    @NamedQuery(name = "Concurso.findByUniversidade", query = "SELECT c FROM Concurso c WHERE c.universidade = :universidade"),
    @NamedQuery(name = "Concurso.findByMisnisterio", query = "SELECT c FROM Concurso c WHERE c.misnisterio = :misnisterio"),
    @NamedQuery(name = "Concurso.findByRegras", query = "SELECT c FROM Concurso c WHERE c.regras = :regras"),
    @NamedQuery(name = "Concurso.findByDataInicio", query = "SELECT c FROM Concurso c WHERE c.dataInicio = :dataInicio")})
public class Concurso implements Serializable {
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "concurso")
    private Collection<Pesoprovas> pesoprovasCollection;
    private static final long serialVersionUID = 1L;
    @Id
    @Basic(optional = false)
    @Column(name = "codigo")
    private Integer codigo;
    @Column(name = "edital")
    private String edital;
    @Column(name = "area")
    private String area;
    @Column(name = "classe")
    private String classe;
    @Column(name = "campus")
    private String campus;
    @Column(name = "universidade")
    private String universidade;
    @Column(name = "misnisterio")
    private String misnisterio;
    @Column(name = "Regras")
    private String regras;
    @Column(name = "dataInicio")
    private String dataInicio;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "concurso")
    private Collection<Tema> temaCollection;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "concurso")
    private Collection<Abertura> aberturaCollection;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "concurso")
    private Collection<Candidato> candidatoCollection;
    @JoinColumn(name = "banca", referencedColumnName = "codigo")
    @ManyToOne(optional = true)
    private Banca banca;

    private static Concurso INSTANCE = null;
    
    public static Concurso getInstance(){
        if(INSTANCE == null){
            return new Concurso();
        } else {
            return INSTANCE;
        }
    }
    
    public static void setInstance(Concurso concurso){
        INSTANCE = concurso;
    }
    

    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public String getEdital() {
        return edital;
    }

    public void setEdital(String edital) {
        this.edital = edital;
    }

    public String getArea() {
        return area;
    }

    public void setArea(String area) {
        this.area = area;
    }

    public String getClasse() {
        return classe;
    }

    public void setClasse(String classe) {
        this.classe = classe;
    }

    public String getCampus() {
        return campus;
    }

    public void setCampus(String campus) {
        this.campus = campus;
    }

    public String getUniversidade() {
        return universidade;
    }

    public void setUniversidade(String universidade) {
        this.universidade = universidade;
    }

    public String getMisnisterio() {
        return misnisterio;
    }

    public void setMisnisterio(String misnisterio) {
        this.misnisterio = misnisterio;
    }

    public String getRegras() {
        return regras;
    }

    public void setRegras(String regras) {
        this.regras = regras;
    }

    public String getDataInicio() {
        return dataInicio;
    }

    public void setDataInicio(String dataInicio) {
        this.dataInicio = dataInicio;
    }

    @XmlTransient
    public Collection<Tema> getTemaCollection() {
        return temaCollection;
    }

    public void setTemaCollection(Collection<Tema> temaCollection) {
        this.temaCollection = temaCollection;
    }

    @XmlTransient
    public Collection<Abertura> getAberturaCollection() {
        return aberturaCollection;
    }

    public void setAberturaCollection(Collection<Abertura> aberturaCollection) {
        this.aberturaCollection = aberturaCollection;
    }

    @XmlTransient
    public Collection<Candidato> getCandidatoCollection() {
        return candidatoCollection;
    }

    public void setCandidatoCollection(Collection<Candidato> candidatoCollection) {
        this.candidatoCollection = candidatoCollection;
    }

    public Banca getBanca() {
        return banca;
    }

    public void setBanca(Banca banca) {
        this.banca = banca;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (codigo != null ? codigo.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Concurso)) {
            return false;
        }
        Concurso other = (Concurso) object;
        if ((this.codigo == null && other.codigo != null) || (this.codigo != null && !this.codigo.equals(other.codigo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Concurso[ codigo=" + codigo + " ]";
    }

    public Concurso() {
    }

    @XmlTransient
    public Collection<Pesoprovas> getPesoprovasCollection() {
        return pesoprovasCollection;
    }

    public void setPesoprovasCollection(Collection<Pesoprovas> pesoprovasCollection) {
        this.pesoprovasCollection = pesoprovasCollection;
    }
    
}
