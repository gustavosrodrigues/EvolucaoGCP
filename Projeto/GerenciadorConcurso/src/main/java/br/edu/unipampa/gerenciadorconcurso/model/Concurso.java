/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.edu.unipampa.gerenciadorconcurso.model;

import java.io.Serializable;
import java.util.Date;
import javax.persistence.Basic;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author user
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
    @NamedQuery(name = "Concurso.findByMinisterio", query = "SELECT c FROM Concurso c WHERE c.ministerio = :ministerio"),
    @NamedQuery(name = "Concurso.findByRegras", query = "SELECT c FROM Concurso c WHERE c.regras = :regras"),
    @NamedQuery(name = "Concurso.findByDataInicio", query = "SELECT c FROM Concurso c WHERE c.dataInicio = :dataInicio"),
    @NamedQuery(name = "Concurso.findByBanca", query = "SELECT c FROM Concurso c WHERE c.banca = :banca")})
public class Concurso implements Serializable {

    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
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
    @Column(name = "ministerio")
    private String ministerio;
    @Column(name = "regras")
    private String regras;
    @Column(name = "dataInicio")
    @Temporal(TemporalType.DATE)
    private Date dataInicio;
    @Column(name = "banca")
    private Integer banca;

    private static Concurso INSTANCE;

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

    public String getMinisterio() {
        return ministerio;
    }

    public void setMinisterio(String ministerio) {
        this.ministerio = ministerio;
    }

    public String getRegras() {
        return regras;
    }

    public void setRegras(String regras) {
        this.regras = regras;
    }

    public Date getDataInicio() {
        return dataInicio;
    }

    public void setDataInicio(Date dataInicio) {
        this.dataInicio = dataInicio;
    }

    public Integer getBanca() {
        return banca;
    }

    public void setBanca(Integer banca) {
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
        return "br.edu.unipampa.gerenciadorconcurso.model.Concurso[ codigo=" + codigo + " ]";
    }

}
