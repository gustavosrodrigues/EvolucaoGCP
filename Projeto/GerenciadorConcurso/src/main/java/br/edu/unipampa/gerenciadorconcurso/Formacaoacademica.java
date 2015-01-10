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
@Table(name = "formacaoacademica")
@XmlRootElement
@NamedQueries({
    @NamedQuery(name = "Formacaoacademica.findAll", query = "SELECT f FROM Formacaoacademica f"),
    @NamedQuery(name = "Formacaoacademica.findByDoutoradoNaArea", query = "SELECT f FROM Formacaoacademica f WHERE f.doutoradoNaArea = :doutoradoNaArea"),
    @NamedQuery(name = "Formacaoacademica.findByDoutoradoEmAreaAfimDaArea", query = "SELECT f FROM Formacaoacademica f WHERE f.doutoradoEmAreaAfimDaArea = :doutoradoEmAreaAfimDaArea"),
    @NamedQuery(name = "Formacaoacademica.findByMestradoNaArea", query = "SELECT f FROM Formacaoacademica f WHERE f.mestradoNaArea = :mestradoNaArea"),
    @NamedQuery(name = "Formacaoacademica.findByMestradoEmAreaAfimDaArea", query = "SELECT f FROM Formacaoacademica f WHERE f.mestradoEmAreaAfimDaArea = :mestradoEmAreaAfimDaArea"),
    @NamedQuery(name = "Formacaoacademica.findByEspecializacaoArea", query = "SELECT f FROM Formacaoacademica f WHERE f.especializacaoArea = :especializacaoArea"),
    @NamedQuery(name = "Formacaoacademica.findByResidenciaRealizada", query = "SELECT f FROM Formacaoacademica f WHERE f.residenciaRealizada = :residenciaRealizada"),
    @NamedQuery(name = "Formacaoacademica.findByConclusaoDoutorado", query = "SELECT f FROM Formacaoacademica f WHERE f.conclusaoDoutorado = :conclusaoDoutorado"),
    @NamedQuery(name = "Formacaoacademica.findByPosDoutoradoArea", query = "SELECT f FROM Formacaoacademica f WHERE f.posDoutoradoArea = :posDoutoradoArea"),
    @NamedQuery(name = "Formacaoacademica.findByPosDoutoradoAreaAfimArea", query = "SELECT f FROM Formacaoacademica f WHERE f.posDoutoradoAreaAfimArea = :posDoutoradoAreaAfimArea"),
    @NamedQuery(name = "Formacaoacademica.findByTitulo", query = "SELECT f FROM Formacaoacademica f WHERE f.titulo = :titulo")})
public class Formacaoacademica implements Serializable {
    private static final long serialVersionUID = 1L;
    // @Max(value=?)  @Min(value=?)//if you know range of your decimal fields consider using these annotations to enforce field validation
    @Column(name = "doutoradoNaArea")
    private Float doutoradoNaArea;
    @Column(name = "doutoradoEmAreaAfimDaArea")
    private Float doutoradoEmAreaAfimDaArea;
    @Column(name = "mestradoNaArea")
    private Float mestradoNaArea;
    @Column(name = "mestradoEmAreaAfimDaArea")
    private Float mestradoEmAreaAfimDaArea;
    @Column(name = "especializacaoArea")
    private Float especializacaoArea;
    @Column(name = "residenciaRealizada")
    private Float residenciaRealizada;
    @Column(name = "conclusaoDoutorado")
    private Float conclusaoDoutorado;
    @Column(name = "PosDoutoradoArea")
    private Float posDoutoradoArea;
    @Column(name = "posDoutoradoAreaAfimArea")
    private Float posDoutoradoAreaAfimArea;
    @Id
    @Basic(optional = false)
    @Column(name = "titulo")
    private Integer titulo;
    @JoinColumn(name = "titulo", referencedColumnName = "codigo", insertable = false, updatable = false)
    @OneToOne(optional = false)
    private Titulo titulo1;

    public Formacaoacademica() {
    }

    public Formacaoacademica(Integer titulo) {
        this.titulo = titulo;
    }

    public Float getDoutoradoNaArea() {
        return doutoradoNaArea;
    }

    public void setDoutoradoNaArea(Float doutoradoNaArea) {
        this.doutoradoNaArea = doutoradoNaArea;
    }

    public Float getDoutoradoEmAreaAfimDaArea() {
        return doutoradoEmAreaAfimDaArea;
    }

    public void setDoutoradoEmAreaAfimDaArea(Float doutoradoEmAreaAfimDaArea) {
        this.doutoradoEmAreaAfimDaArea = doutoradoEmAreaAfimDaArea;
    }

    public Float getMestradoNaArea() {
        return mestradoNaArea;
    }

    public void setMestradoNaArea(Float mestradoNaArea) {
        this.mestradoNaArea = mestradoNaArea;
    }

    public Float getMestradoEmAreaAfimDaArea() {
        return mestradoEmAreaAfimDaArea;
    }

    public void setMestradoEmAreaAfimDaArea(Float mestradoEmAreaAfimDaArea) {
        this.mestradoEmAreaAfimDaArea = mestradoEmAreaAfimDaArea;
    }

    public Float getEspecializacaoArea() {
        return especializacaoArea;
    }

    public void setEspecializacaoArea(Float especializacaoArea) {
        this.especializacaoArea = especializacaoArea;
    }

    public Float getResidenciaRealizada() {
        return residenciaRealizada;
    }

    public void setResidenciaRealizada(Float residenciaRealizada) {
        this.residenciaRealizada = residenciaRealizada;
    }

    public Float getConclusaoDoutorado() {
        return conclusaoDoutorado;
    }

    public void setConclusaoDoutorado(Float conclusaoDoutorado) {
        this.conclusaoDoutorado = conclusaoDoutorado;
    }

    public Float getPosDoutoradoArea() {
        return posDoutoradoArea;
    }

    public void setPosDoutoradoArea(Float posDoutoradoArea) {
        this.posDoutoradoArea = posDoutoradoArea;
    }

    public Float getPosDoutoradoAreaAfimArea() {
        return posDoutoradoAreaAfimArea;
    }

    public void setPosDoutoradoAreaAfimArea(Float posDoutoradoAreaAfimArea) {
        this.posDoutoradoAreaAfimArea = posDoutoradoAreaAfimArea;
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
        if (!(object instanceof Formacaoacademica)) {
            return false;
        }
        Formacaoacademica other = (Formacaoacademica) object;
        if ((this.titulo == null && other.titulo != null) || (this.titulo != null && !this.titulo.equals(other.titulo))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "br.edu.unipampa.gerenciadorconcurso.Formacaoacademica[ titulo=" + titulo + " ]";
    }
    
}
